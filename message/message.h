#ifndef MESSAGE_H
#define MESSAGE_H
#include"../utils/utils.h"
#include "../common/common.h"
#include "messageType.h"
#include <chrono>

class Message  {
    public:
    std::string serializeMessage();
    void deserializeMessage(std::string serializedMessage);
    std::string getRequestId();
    long getTimeStamp();
    int getPort();
    std::string getMemoryAddress();
    MessageType getMessageType();

    friend std::ostream &operator<<(std::ostream &os, const Message &message);
    friend bool operator<(const Message &message, const Message &otherMessage);

        Message(std::string serializedMessage);
        Message(std::string requestId,long timeStamp,int port, std::string memoryAddress, MessageType messageType);
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