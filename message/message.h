#ifndef MESSAGE_H
#define MESSAGE_H
#include"../utils/utils.h"
#include "../common/common.h"
#include "messageType.h"
#include <chrono>

class Message  {
    public:
        Message(std::string serializedMessage);
        Message(std::string requestId,long timestamp,int port
                ,std::string memoryAddress, MessageType messageType);
        Message(const Message &message,int port);

        void setMessageType(MessageType newMessageType);

        std::string getRequestId();
        long getTimeStamp();
        int getPort();
        std::string getMemoryAddress();
        MessaageType getMessageType();

        std::string serializeMessage();
        void deserializeMessage(std::string serializeMessage);


        ~Message();
    private:
        std::string requestId;
        long timeStamp;
        int port;
        std::string memoryAddress;
        MessageType messageType;
        std::string serializeField(std::string fieldValue,bool isLast);


};
#endif