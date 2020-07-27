
#include "main.h"


struct Message {
    std::string hello;
};

int main () {

    //Vec to send 
    std::vector<int> v1;
    for(int i =1;i<=5; i++)
        v1.push_back(i);

    for(auto i=v1.begin();i!=v1.end();++i){
        std::cout<< *i << " ";
    }
    std::cout<<std::endl;
    
    // Prepare context and socket
    zmq::context_t context(1);
    zmq::socket_t socket(context,ZMQ_REP);
    socket.bind("tcp://*:5555");

    while (true){
        zmq::message_t request; 
        std::string rply =s_recv(socket);
        std::cout <<"Received:"<< rply <<std::endl;

        zmq::message_t reply(5);
        memcpy( reply.data(),"World",5);
        socket.send(reply);
    }

    return 0;
} 

