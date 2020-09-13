#ifndef MESSAGETYPE_H
#define MESSAGETYPE_H

#include "../common/common.h"

enum class MessageType {REQUEST,TOKEN};

std::string messageTypeToString(const MessageType &messageType);
MessageType stringToMessageType(const std::string &s_messageType);

#endif