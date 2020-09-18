#include "suzuki-kasami.h"

SuzukiKasami::SuzukiKasami(int _port,bool _hasToken) :port{_port},hasToken{_hasToken}{
    ctx = zmq_ctx_new();
}
SuzukiKasami::~SuzukiKasami(){ zmq_ctx_destroy(ctx);}

void SuzukiKasami::sendRequestMessage(){
    incrementProcessRequestNumber();
    Message message = makeRequest();
    for (auto it = begin (RN); it != end (RN); ++it) {
        std::pair<int,int> toSend = std::make_pair(it->first,it->second);
        if(toSend.first==port) continue;
        sendMessage(message,toSend.first);   
    } 
}

void SuzukiKasami::sendTokenMessage(){
    hasToken=false;
    int _port = token.removeFromQueue();
    Message message{MessageType::TOKEN,_port,token.getLN(),token.getRequestQueue()}; 
    sendMessage(message,_port);
}

void SuzukiKasami::receiveRequestMessage(Message message){
    std::cout<<"Received Request Message from:"
             <<std::to_string(message.getPort())<<std::endl;
    for (auto it = begin (RN); it != end (RN); ++it) {
        if(it->first==message.getPort()){
            if(it->second<message.getSn()) it->second=message.getSn();
        }   
    }
}

void SuzukiKasami::receiveTokenMessage(Message message){
    std::cout<<"Received Token Message form:"
             <<std::to_string(message.getPort())<<std::endl;
    hasToken=true;
    token.updateToken(message);
}

void SuzukiKasami::addRequestSite(int port){
    RN.push_back(std::make_pair(port,0));
    token.addRequestNumber();
}

bool SuzukiKasami::canEnterCriticalSection(){
    return(hasToken==true);
}

void SuzukiKasami::exitCriticalSection(){
    std::vector<int> LN = token.getLN();    
    for(unsigned int i=0;i<RN.size();i++){
        if(RN[i].second==LN[i]+1){
            if(!Utils::isInQueue(token.getRequestQueue(),RN[i].first)){
                token.addToQueue(RN[i].first);
            }

            token.updateLN(i);  
        }
    }
    token.printQueue();
}


bool SuzukiKasami::checkIfSendToken(){return(token.getRequestQueue().size()>0);
std::cout<<"Czekam"<<std::endl;}

int SuzukiKasami::getPort(){return port;}

bool SuzukiKasami::getHasToken(){return hasToken;}

Token SuzukiKasami::getToken(){return token;}

std::vector<std::pair<int,int>> SuzukiKasami::getRN(){return RN;}

Message SuzukiKasami::makeRequest(){
    for(unsigned int i=0;i<RN.size();i++){
        if(RN[i].first==port){
            Message message{MessageType::REQUEST,port,RN[i].second};
            return message;
        }
    }
    Message badMessage{MessageType::REQUEST,0,0};
    return badMessage;  
}

void SuzukiKasami::incrementProcessRequestNumber(){
    for (auto it = begin (RN); it != end (RN); ++it) {
        if(it->first==port) it->second++;     
    }
}

void SuzukiKasami::sendMessage(Message message, int _port){
    void *socket = createZmqSocket(ZMQ_REQ);
    std::string host = HOST_ADDRESS + std::to_string(_port);
    if(zmq_connect(socket, host.c_str()) == 0){
        std::string serializedMessage = message.serializeMessage();
        std::cout<< "Sending to "<<host <<": " << serializedMessage<<std::endl;
        zmq_send(socket,serializedMessage.c_str(),serializedMessage.size(),0);
    }else {
        std::cout<<zmq_strerror(zmq_errno())<<std::endl;
    }
    zmq_close(socket);
}


void *SuzukiKasami::createZmqSocket(int type){
    void *newSocket = zmq_socket(ctx, type);
    return newSocket;
}
