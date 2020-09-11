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

Monitor::Monitor(int port, std::vector<int> otherPorts) :suzukiKasami(port){
    ctx  = zmq_ctx_new();
    receiveSocket = zmq_socket(ctx,ZMQ_REP);

    std::string host = "tcp://127.0.0.1:"+std::to_string(port);
    zmq_bind(receiveSocket,host.c_str());
    std::cout <<"Initialized with address: " << host << std::endl;
    for(const int &otherPort : otherPorts) {
        suzukiKasami.addNewPortNumber(otherPort);
        suzukiKasami.addRequestSite();
    }

    std::cout<<"Has those other ports:" <<std::endl;
    suzukiKasami.displayPortNumbers();

    std::cout<<"Values of request numbers"<<std::endl;
    suzukiKasami.displayRequestNumbers();
    suzukiKasami.displayToken();
    std::thread handlerThread(&Monitor::handleReceivingMessages,this);
    handlerThread.detach();
}

void Monitor::enter(std::string lock){
    suzukiKasami.sendRequestMessage(lock);
    while(!suzukiKasami.canEnterCriticalSection(lock)){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout<<"Monitor withport: ["<<suzukiKasami.getPort()
            <<"] has entered the: ["<< lock<<"]"<<std::endl;
}

Monitor::~Monitor(){
    zmq_close(receiveSocket);
    destoryCtx();
}

void Monitor::destoryCtx(){zmq_ctx_destroy(ctx);}