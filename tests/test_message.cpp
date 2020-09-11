#include "test_message.h"

void runMessageTests(){
    is_serializedProperlyToken();
    is_serializedProperlyRequest();
    is_deserializedProperlyToken();
    is_deserializedProperlyRequest();
}

void is_serializedProperlyToken(){
    std::vector<int> LN= {0,0,0,0,0};
    std::vector<int> RequestQueue = {3,2,1};
    int port = 41;
    Message mes{MessageType::TOKEN,port,"Lock",LN,RequestQueue};
    std::string serializedMessage = mes.serializeMessageToken();
    if(serializedMessage == "TOKEN,41,Lock,0;0;0;0;0,3;2;1"){
        std::cout << "TokenIsSerializedProperly:POSITIVE"<<std::endl;
    } else {
        std::cout << " TokenIsSerializedProperly:NEGATIVE"<<std::endl;
    }
}

void is_serializedProperlyRequest(){
    int port =41;
    int sn = 1;
    Message mes{MessageType::REQUEST,port,sn,"Lock"};
    std::string serializedMessage = mes.serializeMessageRequest();
    if(serializedMessage == "REQUEST,41,1,Lock"){
        std::cout << "RequestIsSerializedProperly:POSITIVE"<<std::endl;
    } else {
        std::cout << " RequestIsSerializedProperly:NEGATIVE"<<std::endl;
    }
}


void is_deserializedProperlyToken() {
    std::string serializedMessage ="TOKEN,41,Lock,0;0;0;0;0,3;2;1";
    Message mes{serializedMessage};
    std::vector<int> LN = {0,0,0,0,0};
    std::vector<int> requestQueue = {3,2,1};
    if(mes.getMessageType()==MessageType::TOKEN&&
       mes.getPort()==41&&
       mes.getLock()=="Lock"&&
       mes.getLN()==LN&&
       mes.getRequestQueue()==requestQueue)
       {
           std::cout<<"TokenIsDeserializedProperly:POSITIVE"<<std::endl;
       }else {
           std::cout<<"TokenIsDeserializedProperly:NEGATIVE"<<std::endl;} 
}

void is_deserializedProperlyRequest() {
    std::string serializedMessage ="REQUEST,41,1,Lock";
    Message mes{serializedMessage};
    if(mes.getMessageType()==MessageType::REQUEST&&
       mes.getPort()==41&&
       mes.getSn()==1&&
       mes.getLock()=="Lock")
       {
           std::cout<<"RequestIsDeserializedProperly:POSITIVE"<<std::endl;
       } else {
           std::cout<<"RequestIsDeserializedProperly:NEGATIVE"<<std::endl;
       } 

}