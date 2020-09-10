#ifndef MESSAGETYPE_H
#define MESSAGETYPE_H

#include "../common/common.h"

enum class MessageType {REQUEST,REPLY,TOKEN};

std::string messageTypeToString(const MessageType &messageType);
MessageType stringToMessageType(const std::string &s_messageType);

std::ostream &operator<<(std::ostream &os,const MessageType &messageType);



#endif