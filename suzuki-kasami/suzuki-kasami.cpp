#include "suzuki-kasami.h"

SuzukiKasami::SuzukiKasami(int _port,bool _hasToken) :port{_port},hasToken{_hasToken}{
    context = zmq_ctx_new();
}

SuzukiKasami::~SuzukiKasami(){ zmq_ctx_destroy(context);}

void *SuzukiKasami::createZmqSocket(int type){
    void *newSocket = zmq_socket(context, type);
    return newSocket;
}


void SuzukiKasami::sendMessage(Message message, int _port){
    void *socket = createZmqSocket(ZMQ_REQ);
    std::string host = HOST_ADDRESS + std::to_string(_port);
    std::cout<<host<<std::endl;
    if(zmq_connect(socket, host.c_str()) == 0){
        std::cout<< "Sending to "<<host <<": " << message<<std::endl;
        std::string serializedMessage = message.serializeMessage();
        
        zmq_send(socket,serializedMessage.c_str(),serializedMessage.size(),0);
    }else {
        std::cout<<zmq_strerror(zmq_errno())<<std::endl;
    }
    zmq_close(socket);
}


void SuzukiKasami::closeZmqSocket(void *socket){
    zmq_close(socket);
}

void SuzukiKasami::receiveRequestMessage(Message message){
    std::cout<<"Received Request Message"<<std::endl;

    for (auto it = begin (RN); it != end (RN); ++it) {
    if(it->first==message.getPort()){
            if(it->second<message.getSn()){
                it->second=message.getSn();
            }
        }   
    }
}

void SuzukiKasami::receiveTokenMessage(Message message){
    // Message is MessageType,Port,LN,requestQueue
    std::cout<<"Received Token Message"<<std::endl;
    hasToken=true;
    token.updateToken(message);
}


void SuzukiKasami::addRequestSite(int port){ RN.push_back(std::make_pair(port,0)); token.addRequestNumber();}


bool SuzukiKasami::canEnterCriticalSection(){
    if(hasToken==true)
        return true;
    else
        return false;
}

void SuzukiKasami::exitCriticalSection(){
    hasToken=false;
    std::vector<int> LN = token.getLN();    
    for(unsigned int i=0;i<RN.size();i++){
        if(RN[i].second==LN[i]+1){
            if(!Utils::isInQueue(token.getRequestQueue(),i))
                token.addToQueue(i);
            token.updateLN(i);  
        }
    }
    std::cout<<std::to_string(token.getRequestQueue().size());
    sendTokenMessage();
}


void SuzukiKasami::sendRequestMessage(){
    incrementProcessRequestNumber();
    for (auto it = begin (RN); it != end (RN); ++it) {
        std::pair<int,int> toSend = std::make_pair(it->first,it->second);
        Message message{MessageType::REQUEST,toSend.first,toSend.second}; 
        sendMessage(message,toSend.first);
    } 
}

void SuzukiKasami::sendTokenMessage(){
    int _port =token.removeFromQueue();
    Message message{MessageType::TOKEN,_port,token.getLN(),token.getRequestQueue()}; 
    sendMessage(message,_port);
}

void SuzukiKasami::displayToken(){std::cout<<"Token Last Request Numbers"<<std::endl;
token.displayLastRequestNumbers();
std::cout<<"Token Request Queue (if nothing its empty)"<<std::endl;
}

void SuzukiKasami::incrementProcessRequestNumber(){
    for (auto it = begin (RN); it != end (RN); ++it) {
        if(it->first==port){
                it->second++;
            }   
    }
}

std::pair<int,int> SuzukiKasami::getProcessIdAndRequestNumber(){
    for (auto it = begin (RN); it != end (RN); ++it){
        if(it->first==port){
            int port=it->first;
            int RN=it->second;
            std::pair<int,int> output = std::make_pair(port,RN);
            return output;
        } 
    }
    return std::make_pair(-1,-1);
}
int SuzukiKasami::getPort(){return port;}

bool SuzukiKasami::getHasToken(){return hasToken;}

Token SuzukiKasami::getToken(){return token;}

std::vector<std::pair<int,int>> SuzukiKasami::getRN(){return RN;}