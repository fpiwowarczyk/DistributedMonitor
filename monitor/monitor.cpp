#include "monitor.h"

void Monitor::handleReceivingMessages(){
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
            switch (message.getMessageType()){
                case MessageType::REQUEST: {
                    suzukiKasami.receiveRequestMessage(message);
                    break;
                }
                case MessageType::TOKEN: {
                    suzukiKasami.receiveTokenMessage(message);
                    break;
                }
            }
        }
    }
}


void Monitor::enter(){

    std::cout<<"Monitor withport: ["<<suzukiKasami.getPort()
            <<"] has requested the critical section"<<std::endl;
    if(!suzukiKasami.getHasToken()){
        suzukiKasami.sendRequestMessage();
        while(!suzukiKasami.canEnterCriticalSection()){
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
    std::cout<<"Monitor withport: ["<<suzukiKasami.getPort()
            <<"] has entered the critical section"<<std::endl;
}

void Monitor::exit(){
    suzukiKasami.exitCriticalSection();
}

void Monitor::wait(){
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
}
Monitor::Monitor(int port, std::vector<int> otherPorts) :suzukiKasami(port){
    ctx  = zmq_ctx_new();
    receiveSocket = zmq_socket(ctx,ZMQ_REP);

    std::string host = "tcp://127.0.0.1:"+std::to_string(port);
    zmq_bind(receiveSocket,host.c_str());
    std::cout <<"Initialized with address: " << host << std::endl;
    for(const int &otherPort : otherPorts) {
        suzukiKasami.addRequestSite(otherPort);
    }
    std::thread handlerThread(&Monitor::handleReceivingMessages,this);
    handlerThread.detach();
}

Monitor::~Monitor(){
    zmq_close(receiveSocket);
    destoryCtx();
}

void Monitor::destoryCtx(){zmq_ctx_destroy(ctx);}

SuzukiKasami Monitor::getSuzukiKasami(){return suzukiKasami;}