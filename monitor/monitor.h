#ifndef MONITOR_H
#define MONITOR_H

#include"zmq.hpp"
#include<iostream>
#include<thread>
class Monitor {

    public:
    Monitor(int port,std::vector<int> otherPorts);
    ~Monitor();
    private:
    void *context;
    void *receiveSocket;
    void handleReceivingMessages();
    void processMessage();
    void destrooContext();
};

#endif