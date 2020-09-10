#include "suzuki-kasami.h"

SuzukiKasami::SuzukiKasami(int port) :port{port}{
   ctx = zmq_ctx_new();
   requestId = 0;
}

SuzukiKasami::~SuzukiKasami(){ zmq_ctx_destroy(ctx); }



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


void SuzukiKasami::addNewPortNumber(int port){
    ports.push_back(port);
}

void SuzukiKasami::removePortNumber(int port){
    int index;
    if((index = std::find(ports.begin(), ports.end(),port)!= ports.end())){
        ports.erase(ports.begin()+index);
    }
}


void SuzukiKasami::displayPortNumbers(){
    Utils::displayVector(ports);
}

