#include "monitor.h"

Monitor::Monitor(int port, std::vector<int> otherPorts,bool hasToken) :suzukiKasami(port,hasToken){
    ctx  = zmq_ctx_new();
    receiveSocket = zmq_socket(ctx,ZMQ_REP);
    std::string host = HOST_ADDRESS+std::to_string(port);
    zmq_bind(receiveSocket,host.c_str());
    std::cout <<"Start with addresss: " << host << std::endl;
    otherPorts.push_back(port);
    otherPorts=Utils::sortVector(otherPorts);
    for(const int &otherPort : otherPorts) {
        suzukiKasami.addRequestSite(otherPort);
    }
    std::thread handlerThread(&Monitor::handleReceivingMessages, this);
    handlerThread.detach();
}

Monitor::~Monitor(){
    std::cout<<"Monitor destroyed"<<std::endl;
    zmq_close(receiveSocket);
    destoryCtx();
}
void Monitor::enter(){
    std::cout<<"Monitor withport: ["<<suzukiKasami.getPort()
             <<"] has requested the critical section"<<std::endl;
    if(!suzukiKasami.getHasToken()){
        suzukiKasami.sendRequestMessage();
        while(!suzukiKasami.canEnterCriticalSection())wait();
    }
    std::cout<<"Monitor withport: ["<<suzukiKasami.getPort()
             <<"] has entered the critical section"<<std::endl;
}

void Monitor::wait(){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Monitor::exit(){
    std::cout<<"Monitor leaves ciritical section"<<std::endl;
    suzukiKasami.exitCriticalSection();
    if(suzukiKasami.checkIfSendToken()){
        suzukiKasami.sendTokenMessage();
    }
    
}

void Monitor::destoryCtx(){zmq_ctx_destroy(ctx);}

void Monitor::handleReceivingMessages(){
  std::cout << "Messages handler start" << std::endl;
  char *buffer = new char[BUFFER_SIZE];
  while (true) {
    memset(buffer, 0, BUFFER_SIZE);
    if (zmq_recv(receiveSocket, buffer, BUFFER_SIZE, 0) > -1) {
        zmq_send(receiveSocket, "", 0, 0);
        std::string serializedMessage =
            std::string(reinterpret_cast<char const *>(buffer),
                      std::char_traits<char>::length(buffer));
      Message message{serializedMessage};
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