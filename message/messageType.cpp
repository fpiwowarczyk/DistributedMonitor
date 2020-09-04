#include "messageType.h"


std::string messageTypeToString(const MessageType &messageType){
    switch(messageType){
        case MessageType::REPLY:{
            return "REPLY";
            
        }
        case MessageType::REMOVE: {
            return "REMOVE";
        }
        case MessageType::REQUEST: {
            return "REQUEST";
        }
        default: {
            return "REPLY";
        }
    }
}

MessageType stringToMessageType(const std::string &s_messageType){
    if(s_messageType=="REPLY")
        return MessageType::REPLY;
    else if(s_messageType=="REQUEST")
        return MessageType::REQUEST;
    else if(s_messageType=="REMOVE")
        return MessageType::REQUEST;
}

std::ostream &operator <<(std::ostream &os,const MessageType &messageType){
    os<<messageTypeToString(messageType);
    return os;
}