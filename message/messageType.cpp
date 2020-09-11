#include "messageType.h"


std::string messageTypeToString(const MessageType &messageType){
    switch(messageType){
        case MessageType::TOKEN: {
            return "TOKEN";
        }
        case MessageType::REQUEST: {
            return "REQUEST";
        }
    }
}

MessageType stringToMessageType(const std::string &s_messageType){
    if(s_messageType=="TOKEN")
        return MessageType::TOKEN;
    else if(s_messageType=="REQUEST")
        return MessageType::REQUEST;
}

std::ostream &operator <<(std::ostream &os,const MessageType &messageType){
    os<<messageTypeToString(messageType);
    return os;
}