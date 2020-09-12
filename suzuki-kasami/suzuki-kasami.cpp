#include "suzuki-kasami.h"

SuzukiKasami::SuzukiKasami(int port) :port{port}{ctx = zmq_ctx_new();}

SuzukiKasami::~SuzukiKasami(){ zmq_ctx_destroy(ctx);}



void SuzukiKasami::sendMessage(Message message, int _port){
    void *socket = createZmqSocket(ZMQ_REQ);
    std::string host = HOST_ADDRESS+std::to_string(_port);
    if(zmq_connect(socket,host.c_str())==0){
        std::cout<< "Sending to "<<host <<": " << message<<std::endl;
        std::string serializedMessage = message.serializeMessage();
        
        zmq_send(socket,serializedMessage.c_str(),serializedMessage.size(),0);
    }else {
        std::cout<<zmq_strerror(zmq_errno())<<std::endl;
    }
    zmq_close(socket);
}

void *SuzukiKasami::createZmqSocket(int type){
    void *newSocket = zmq_socket(ctx,type);
    return newSocket;
}

void SuzukiKasami::closeZmqSocket(void *socket){
    zmq_close(socket);
}

void SuzukiKasami::receiveRequestMessage(Message message){
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
    hasToken=true;
    token.updateToken(message);
}


void SuzukiKasami::addRequestSite(int port){ RN.push_back(std::make_pair(port,0)); token.addRequestNumber();}


bool SuzukiKasami::canEnterCriticalSection(){
    return hasToken==true;
}

void SuzukiKasami::exitCriticalSection(){
    hasToken=false;
    std::vector<int> LN = token.getLN();    
    for(int i=0;i<RN.size();i++){
        if(RN[i].second==LN[i]+1){
            if(!Utils::isInQueue(token.getRequestQueue(),i))
                token.addToQueue(i);
            token.updateLN(i);  
        }
    }
    sendTokenMessage();
}


void SuzukiKasami::sendRequestMessage(){
    incrementProcessRequestNumber();
    std::pair<int,int> toSend = getProcessIdAndRequestNumber(); // Port and Request Number
    Message message{MessageType::REQUEST,toSend.first,toSend.second}; 
    sendMessage(message,toSend.first);
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
                std::pair<int,int> output = std::make_pair(it->first,it->second);
                return output;
            } 
    }
    return std::make_pair(-1,-1);
}
int SuzukiKasami::getPort(){return port;}

bool SuzukiKasami::getHasToken(){return hasToken;}

Token SuzukiKasami::getToken(){return token;}

std::vector<std::pair<int,int>> SuzukiKasami::getRN(){return RN;}