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
    //Serialization
        std::string serializeMessage();

        void deserializeMessage(std::string serializedMessage);
    // I think i maight delete it
        friend std::ostream &operator<<(std::ostream &os, const Message &message);
    //Constructors
        Message(std::string serializedMessage);
        Message(MessageType messageType,int port,int sn);
        Message(MessageType messageType,int port,std::vector<int> LN,
                std::queue<int> requestQueue);
        ~Message();

     //Getters
        MessageType getMessageType();
        int getPort();
        int getSn();
        std::queue<int> getRequestQueue();
        std::vector<int> getLN();

    private:
        MessageType messageType; // Token or Requests
        int port; // Port is an ID of requesting site 
        int sn;
        std::vector<int> LN;
        std::queue<int> requestQueue;

        std::string serializeMessageToken();
        std::string serializeMessageRequest();
        std::string serializeField(std::string fieldValue,bool isLast);
};
#endif