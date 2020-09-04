#include "monitor.h"

Monitor::Monitor(int port, std::vector<int> otherPorts) :  ricartAgrawala(port) {
    ctx  = zmq_ctx_new();
    receiveSocket = zmq_socket(ctx,ZMQ_REP);

    std::string host = "tcp://127.0.0.1:"+std::to_string(port);
    zmq_bind(receiveSocket,host.c_str());
    std::cout <<"Initialized with address: " << host << std::endl;
    for(const int &otherPort : otherPorts) {
        ricartAgrawala.addNewPortNumber(otherPort);
    }
    std::cout<<"Has those other ports:" <<std::endl;
    ricartAgrawala.displayPortNumbers();
}

void Monitor::destoryCtx(){zmq_ctx_destroy(ctx);}

Monitor::~Monitor(){
    zmq_close(receiveSocket);
    destoryCtx();
}