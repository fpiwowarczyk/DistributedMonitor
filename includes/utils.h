#ifndef UTILS_H
#define UTILS_H

#include <zmq.hpp>
#include <zmqpp/zmqpp.hpp>

#include <string>

std::string s_recv (zmq::socket_t & socket);


#endif