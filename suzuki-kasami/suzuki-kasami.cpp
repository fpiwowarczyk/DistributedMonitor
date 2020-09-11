#include "suzuki-kasami.h"

SuzukiKasami::SuzukiKasami(int port) :port{port}{ctx = zmq_ctx_new();}

SuzukiKasami::~SuzukiKasami(){ zmq_ctx_destroy(ctx);}



void SuzukiKasami::sendMessage(Message message, int port){
    void *socket = createZmqSocket(ZMQ_REQ);
}

void *SuzukiKasami::createZmqSocket(int type){
    void *newSocket = zmq_socket(ctx,type);
    return newSocket;
}

void SuzukiKasami::closeZmqSocket(void *socket){
    zmq_close(socket);
}

void SuzukiKasami::receiveRequestMessage(Message message){

}

void SuzukiKasami::receiveTokenMessage(Message message){

}

void SuzukiKasami::addNewPortNumber(int port){ports.push_back(port);}

void SuzukiKasami::addRequestSite(){ RN.push_back(0); token.addRequestNumber();}

void SuzukiKasami::removePortNumber(int port){
    int index;
    if((index = std::find(ports.begin(), ports.end(),port)!= ports.end())){
        ports.erase(ports.begin()+index);
    }
}

bool SuzukiKasami::canEnterCriticalSection(std::string lock){
    return hasToken==true;
}

int SuzukiKasami::getPort(){
    return port;
}

Message SuzukiKasami::sendRequestMessage(std::string lock){
    Message message{MessageType::TOKEN,41,1,"Lock"}; // TODO
    return message;
}
void SuzukiKasami::displayRequestNumbers(){Utils::displayVector(RN);}
void SuzukiKasami::displayPortNumbers(){Utils::displayVector(ports);}
void SuzukiKasami::displayToken(){std::cout<<"Token Last Request Numbers"<<std::endl;
token.displayLastRequestNumbers();
std::cout<<"Token Request Queue (if nothing its empty)"<<std::endl;
}