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

    //Messages
        void sendRequestMessage();
        void sendTokenMessage();
        
    //Portons on PORTS

        void addRequestSite(int port);
        
        


        bool canEnterCriticalSection();
        void exitCriticalSection();
        void displayToken();

        //Message handling
        void receiveRequestMessage(Message message);
        void receiveTokenMessage(Message message);

        int getPort();
        bool getHasToken();
        Token getToken();
        std::vector<std::pair<int,int>> getRN();
        bool checkIfSendToken();
    private:
        Message makeRequest();
        void incrementProcessRequestNumber();
        
    // Private Functions 
        void sendMessage(Message message, int port);
        //Socket operations 
        void *createZmqSocket(int type);
        void closeZmqSocket(void *socket);
    //Variables
        void *ctx;  
        int port;
        int id;
        Token token;
        bool hasToken;
    //Conteners
        std::vector<std::pair<int,int>> RN; // PORTS + Request Numbers



}; // SuzukiKasami class declaration 


#endif 