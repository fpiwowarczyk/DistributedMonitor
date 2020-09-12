#include "message.h"


//Constructors
Message::Message(std::string serializedMessage){
    deserializeMessage(serializedMessage);
}
Message::Message( MessageType  _messageType, int _port,int _sn, std::string _lock)
                : messageType{_messageType},port{_port},sn{_sn},lock{_lock}{ }

Message::Message(MessageType _messageType, int _port, std::string _lock,
                    std::vector<int> _LN,std::vector<int> _requestQueue):
                    messageType{_messageType}, port{_port}, lock{_lock},
                    LN{_LN},requestQueue{_requestQueue}{ }

Message::~Message(){}

std::string Message::serializeMessage(){
        std::string serializedMessage="";
        if(getMessageType()==MessageType::REQUEST){
             serializedMessage += serializeMessageRequest();
        } else if (getMessageType()==MessageType::TOKEN){
             serializedMessage += serializeMessageToken();
        }
        return serializedMessage;
}
std::string Message::serializeMessageToken(){
    std::string serialized ="";
    serialized += serializeField(messageTypeToString(messageType),false);
    serialized += serializeField(std::to_string(port),false);
    serialized += serializeField(lock,false);
    serialized += serializeField(Utils::vectorToString(LN),false);
    serialized += serializeField(Utils::vectorToString(requestQueue),true);

    return serialized;
}
std::string Message::serializeMessageRequest(){
    std::string serialized = "";
    serialized += serializeField(messageTypeToString(messageType),false);
    serialized += serializeField(std::to_string(port),false);
    serialized += serializeField(std::to_string(sn),false);
    serialized += serializeField(lock,true);
    return serialized;
}
std::string Message::serializeField(std::string fieldValue,bool isLast){
    switch(isLast){
        case false:
            return fieldValue +",";
        case true:
            return fieldValue;
    }
}
void Message::deserializeMessage(std::string serializedMessage){
    std::vector<std::string> fieldsValues = 
        Utils::splitString(serializedMessage,',');
    std::string Type = fieldsValues[0];
    if(Type == "TOKEN"){ // Handle Token Message
        messageType=stringToMessageType(fieldsValues[0]);
        port = std::stoi(fieldsValues[1]);
        lock = fieldsValues[2];
        std::string s_LN = fieldsValues[3];
        std::string s_requestQueue = fieldsValues[4];

        std::vector<std::string> LN_parts=
         Utils::splitString(s_LN,';');
         for(std::string part:LN_parts){
            LN.push_back(std::stoi(part));
         }
         std::vector<std::string> requestQueue_parts=
         Utils::splitString(s_requestQueue,';');
         for(std::string part:requestQueue_parts){
             requestQueue.push_back(std::stoi(part));
         }
    }else if(Type == "REQUEST"){ // Handle Request message
        messageType=stringToMessageType(fieldsValues[0]);
        port = std::stoi(fieldsValues[1]);
        sn=std::stoi(fieldsValues[2]);
        lock = fieldsValues[3];
    }
}

std::ostream &operator<<(std::ostream &os, const Message &message) {
  os << "{" << std::endl;
  os << "Port: " << message.port << std::endl;
  os << "Memory Address: " << message.lock << std::endl;
  os << "Message type: " << message.messageType << std::endl;
  os << "}" << std::endl;

  return os;
}
// Getters
int Message::getPort() {return port;}

int Message::getSn(){return sn;}

std::string Message::getLock(){return lock;}

MessageType Message::getMessageType(){return messageType;}

std::vector<int> Message::getRequestQueue(){return requestQueue;}

std::vector<int> Message::getLN(){return LN;}