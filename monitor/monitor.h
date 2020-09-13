#ifndef MONITOR_H
#define MONITOR_H
#include "../suzuki-kasami/suzuki-kasami.h"
#include "../common/common.h"
#include "../utils/utils.h"
#include"zmq.h"
#include<cstring>
#include<thread>
#include<vector>

class Monitor {

    public:
        Monitor(int port, std::vector<int> otherPorts,bool hasToken);
        ~Monitor();
        void enter();
        void wait();
        void exit();
    private:
        SuzukiKasami suzukiKasami;
        void *ctx;
        void *receiveSocket;
        void destoryCtx();
        void handleReceivingMessages();
        
};

#endif