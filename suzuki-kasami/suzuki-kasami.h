#ifndef SUZUKI_KASAMI_H
#define SUZUKI_KASAMI_H
#include "../message/message.h"
#include "../common/common.h"
#include "../utils/utils.h"
#include "./token.h"
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
        Message sendRequestMessage(std::string lock);
        
    //Portons on PORTS

        void addNewPortNumber(int port);
        void addRequestSite();
        void removePortNumber(int port);
        
        int getPort();

        void displayPortNumbers();
        void displayRequestNumbers();

        bool canEnterCriticalSection(std::string lock);
        void exitCriticalSection(std::string lock);
        void displayToken();

        //Message handling
        void receiveRequestMessage(Message message);
        void receiveTokenMessage(Message message);

    private:
    // Private Functions 
        void sendMessage(Message message, int port);
        //Socket operations 
        void *createZmqSocket(int type);
        void closeZmqSocket(void *socket);
    //Variables
        void *ctx;
        int port; // Site ID
        Token token;
        bool hasToken;
    //Conteners
        std::vector<int> RN;
        std::vector<int> ports;



}; // SuzukiKasami class declaration 


#endif 