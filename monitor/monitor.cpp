#include "monitor.h"


void Monitor::handleReceivingMessages(){
    int len;
    std::cout<< "Handler function is initialized" <<std::endl;
    char *buffer = new char[BUFFER_SIZE];
    while(true){
        memset(buffer,0,BUFFER_SIZE);
        if(zmq_recv(receiveSocket,buffer,BUFFER_SIZE,0)>-1){
            std::cout<<"Got message";
            zmq_send(receiveSocket,"",0,0);
            std::string serializedMessage = 
                std::string(reinterpret_cast<char const  *>(buffer),
                            std::char_traits<char>::length(buffer));
            Message message(serializedMessage);
        }
    }
}

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
    std::thread handlerThread(&Monitor::handleReceivingMessages,this);
    handlerThread.detach();
}



Monitor::~Monitor(){
    zmq_close(receiveSocket);
    destoryCtx();
}

void Monitor::destoryCtx(){zmq_ctx_destroy(ctx);}