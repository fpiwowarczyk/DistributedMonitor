#ifndef MESSAGE_H
#define MESSAGE_H
#include"../utils/utils.h"
#include "../common/common.h"
#include "messageType.h"
#include <chrono>
#include <vector>
#include <queue>

class Message  {
    public:
        Message(std::string serializedMessage);
        Message(MessageType messageType,int port,int sn);
        Message(MessageType messageType,int port,std::vector<int> LN,
                std::queue<int> requestQueue);

        std::string serializeMessage();

        void deserializeMessage(std::string serializedMessage);


        MessageType getMessageType();
        int getPort();
        int getSn();
        std::vector<int> getLN();
        std::queue<int> getRequestQueue();
    private:
        MessageType messageType;
        int port;  
        int sn;
        std::vector<int> LN;
        std::queue<int> requestQueue;

        std::string serializeMessageToken();
        std::string serializeMessageRequest();
};
#endif