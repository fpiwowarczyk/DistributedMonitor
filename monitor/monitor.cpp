#include "monitor.h"


void Monitor::wait(){
    

}

void Monitor::pulse(){

}

void Monitor::pulseAll(){

}
Monitor::Monitor(int port, std::vector<int> otherPorts) :suzukiKasami(port){
    ctx  = zmq_ctx_new();
    receiveSocket = zmq_socket(ctx,ZMQ_REP);

    std::string host = "tcp://127.0.0.1:"+std::to_string(port);
    zmq_bind(receiveSocket,host.c_str());
    std::cout <<"Initialized with address: " << host << std::endl;
    for(const int &otherPort : otherPorts) {
        suzukiKasami.addNewPortNumber(otherPort);
    }
    std::cout<<"Has those other ports:" <<std::endl;
    suzukiKasami.displayPortNumbers();
}



Monitor::~Monitor(){
    zmq_close(receiveSocket);
    destoryCtx();
}

void Monitor::destoryCtx(){zmq_ctx_destroy(ctx);}