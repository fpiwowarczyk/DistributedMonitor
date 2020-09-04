#ifndef MONITOR_H
#define MONITOR_H
#include "../common/common.h"
#include "../ricart-agrawala/ricart-agrawala.h"

#include"zmq.h"
#include<cstring>
#include<iostream>
#include<thread>
class Monitor {

    public:
        Monitor(int port,std::vector<int> otherPorts);
        ~Monitor();
        
    private:
        RicartAgrawala ricartAgrawala;
        void *ctx;
        void *receiveSocket;
        void destoryCtx();
};

#endif