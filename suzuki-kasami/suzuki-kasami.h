#ifndef SUZUKI_KASAMI_H
#define SUZUKI_KASAMI_H
#include "../message/message.h"
#include "../common/common.h"
#include "../utils/utils.h"
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <zmq.h>

class SuzukiKasami{

    public:
        SuzukiKasami(int port);
        ~SuzukiKasami();

    //Messages
        Message sendRequestMessage(std::string address);
        
    //Portons on PORTS
        void addNewPortNumber(int port);
        void removePortNumber(int port);
        void displayPortNumbers();
    
    private:
    // Private Functions 
        void sendMessage(Message message, int port);
        //Socket operations 
        void *createZmqSocket(int type);
        void closeZmqSocket(void *socket);
    //Variables
        void *ctx;
        int port;
        int requestId;
    //Conteners
        std::vector<int> ports;
        std::vector<std::pair<long,Message>> requestQueue;



}; // SuzukiKasami class declaration 


#endif 