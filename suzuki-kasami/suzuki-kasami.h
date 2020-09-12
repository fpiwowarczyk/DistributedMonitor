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
        void sendRequestMessage(std::string lock);
        void sendTokenMessage(std::string lock);
        
    //Portons on PORTS

        void addRequestSite(int Port);
        void removePortNumber(int port);
        
        


        bool canEnterCriticalSection(std::string lock);
        void exitCriticalSection(std::string lock);
        void displayToken();

        //Message handling
        void receiveRequestMessage(Message message);
        void receiveTokenMessage(Message message);

        int getPort();
        std::vector<std::pair<int,int>> getRN();
        std::pair<int,int> getProcessIdAndRequestNumber();
    private:
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
        std::vector<int> ports;



}; // SuzukiKasami class declaration 


#endif 