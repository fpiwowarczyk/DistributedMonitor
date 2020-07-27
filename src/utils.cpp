

#include "utils.h"

std::string s_recv (zmq::socket_t & socket) {

    zmq::message_t message;
    socket.recv(&message,0);

    return std::string(static_cast<char*>(message.data()), message.size());
}

int add(int x, int y){
    return x+y;
}
