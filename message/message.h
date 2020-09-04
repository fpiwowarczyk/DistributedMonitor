#ifndef MESSAGE_H
#define MESSAGE_H
#include"../utils/utils.h"
#include "../common/common.h"
#include "messageType.h"
#include <chrono>

class Message  {
    public:
        Message();
        ~Message();
    private:
    std::string requestId;
    int port;
    long timeStamp;
    std::string memoryAddress;
    MessageType messageType;


};
#endif