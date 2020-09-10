#include "test_message.h"

void runMessageTests(){
    is_serializedProperly();
    is_deserializedProperly();
}

void is_serializedProperly(){
    Message mes{"15_0",121312412,43,"SMTH",MessageType::REPLY};
    std::string serializedMessage = mes.serializeMessage();
    std::cout << serializedMessage<<std::endl;
    if(serializedMessage == "15_0,121312412,43,SMTH,REPLY"){
        std::cout << "isSerializedProperly:POSITIVE"<<std::endl;
    } else {
        std::cout << " isSerializedProperly:NEGATIVE"<<std::endl;
    }
}

void is_deserializedProperly() {
    std::string serializedMessage = "15_0,121312412,43,SMTH,REPLY";
    Message message{serializedMessage};

    if(message.getRequestId()=="15_0"&&
       message.getTimeStamp()==121312412&&
       message.getMemoryAddress()=="SMTH"&&
       message.getMessageType()==MessageType::REPLY){
           std::cout<<"is_deserializedProperly: POSITIVE"<<std::endl;
       } else {
           std::cout<<"is_deserializedProperly: NEGATIVE"<<std::endl;
       }
}