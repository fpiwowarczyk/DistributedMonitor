#include "message.h"


//Constructors
Message::Message(std::string serializedMessage){
    deserializeMessage(serializedMessage);
}
Message::Message( MessageType  _messageType, int _port,int _sn)
                : messageType{_messageType},port{_port},sn{_sn}{ }

Message::Message(MessageType _messageType, int _port,
                    std::vector<int> _LN,std::queue<int> _requestQueue):
                    messageType{_messageType}, port{_port},
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
    serialized += serializeField(Utils::vectorToString(LN),false);
    serialized += serializeField(Utils::queueToString(requestQueue),true);

    return serialized;
}
std::string Message::serializeMessageRequest(){
    std::string serialized = "";
    serialized += serializeField(messageTypeToString(messageType),false);
    serialized += serializeField(std::to_string(port),false);
    serialized += serializeField(std::to_string(sn),true);
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
        std::string s_LN = fieldsValues[2];
        std::string s_requestQueue = fieldsValues[3];

        std::vector<std::string> LN_parts=
         Utils::splitString(s_LN,';');
         for(std::string part:LN_parts){
            LN.push_back(std::stoi(part));
         }
         std::vector<std::string> requestQueue_parts=
         Utils::splitString(s_requestQueue,';');
         for(std::string part:requestQueue_parts){
             requestQueue.push(std::stoi(part));
         }
    }else if(Type == "REQUEST"){ // Handle Request message
        messageType=stringToMessageType(fieldsValues[0]);
        port = std::stoi(fieldsValues[1]);
        sn=std::stoi(fieldsValues[2]);;
    }
}

std::ostream &operator<<(std::ostream &os, const Message &message) {
  os << "{" << std::endl;
  os << "Port: " << message.port << std::endl;
  os << "Message type: " << message.messageType << std::endl;
  os << "}" << std::endl;

  return os;
}
// Getters
int Message::getPort() {return port;}

int Message::getSn(){return sn;}


MessageType Message::getMessageType(){return messageType;}

std::queue<int> Message::getRequestQueue(){return requestQueue;}

std::vector<int> Message::getLN(){return LN;}