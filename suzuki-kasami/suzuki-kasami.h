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
        SuzukiKasami(int port,bool hasToken);
        ~SuzukiKasami();

        void sendRequestMessage();
        void sendTokenMessage();
        
        void receiveRequestMessage(Message message);
        void receiveTokenMessage(Message message);

        void addRequestSite(int port);

        bool canEnterCriticalSection();
        void exitCriticalSection();

        bool checkIfSendToken();

        int getPort();
        bool getHasToken();
        Token getToken();
        std::vector<std::pair<int,int>> getRN();
        
    private:
        Message makeRequest();
        void incrementProcessRequestNumber();
        
        void sendMessage(Message message, int port);
        void *createZmqSocket(int type);

        void *ctx;  
        int port;
        int id;
        Token token;
        bool hasToken;
        std::vector<std::pair<int,int>> RN; // PORTS + Request Numbers
};


#endif 