#include "kons.h"



int main ()
{
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);

    std::cout << "Connecting to server"<<std::endl;

    socket.connect("tcp://localhost:5555");

    for(int request_nbr=0;request_nbr!=10;request_nbr++){
        zmq::message_t request(5);
        memcpy(request.data (), "Hello", 5);
        std::cout <<"Sending Hello " << request_nbr << "..." << std::endl;
        socket.send(request);

        //Get the reply  
        std::string rpl= s_recv(socket);
        std::cout <<"Received: "<< rpl <<std::endl;
        //std::cout << "Received World " << request_nbr <<std::endl;
    }
    return 0;
}