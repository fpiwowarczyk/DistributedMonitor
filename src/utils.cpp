#include "utils.h"

std::string s_recv (zmq::socket_t & socket) {

    zmq::message_t message;
    socket.recv(&message,0);

    return std::string(static_cast<char*>(message.data()), message.size());
}

bool stringSend(zmq::socket_t & socket, const std::string & string){
    zmq::message_t message(string.size());
    memcpy (message.data(), string.data(), string.size());

    bool rc = socket.send (message, 0);
    return (rc);
}

bool structSend(zmq::socket_t & socket)