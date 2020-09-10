#ifndef MONITOR_H
#define MONITOR_H
#include "../suzuki-kasami/suzuki-kasami.h"
#include "../common/common.h"

#include"zmq.h"
#include<cstring>
#include<thread>
#include<vector>

class Monitor {

    public:
        Monitor(int port, std::vector<int> otherPorts);
        ~Monitor();
        void enter(std::string lock);
    private:
        SuzukiKasami suzukiKasami;
        void *ctx;
        void *receiveSocket;
        void destoryCtx();
        void handleReceivingMessages();
};

#endif