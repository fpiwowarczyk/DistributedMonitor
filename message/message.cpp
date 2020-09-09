#include "message.h"

Message::Message(std::string serializedMessage){
    std::cout<<"Have serialized message"<<std::endl;
}

Message::Message(std::string _requestId,long _timeStamp,int _port,std::string _memoryAddress, MessageType _messageType)
:requestId{_requestId},timeStamp{_timeStamp},port{_port},memoryAddress{_memoryAddress},messageType{_messageType}{}
Message::~Message(){
    std::cout<<"Destroy Message"<<std::endl;
}

std::string Message::getRequestId(){return requestId;}

long Message::getTimeStamp(){return timeStamp;}

int Message::getPort() {return port;}

std::string Message::getMemoryAddress(){return memoryAddress;}

MessageType Message::getMessageType(){return messageType;}
