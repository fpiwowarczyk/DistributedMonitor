#include "test_message.h"

void runMessageTests(){
    bool test1=is_serializedProperlyToken();
    bool test2=is_serializedProperlyRequest();
    bool test3=is_deserializedProperlyToken();
    bool test4=is_deserializedProperlyRequest();
    if(test1&&test2&&test3&&test4){
        std::cout<<"Messages tests:POSITIVE"<<std::endl;
    } else {
        std::cout<<"Messages tests:NEGATIVE"<<std::endl;
    }
}

bool is_serializedProperlyToken(){
    std::vector<int> LN= {0,0,0,0,0};
    std::vector<int> RequestQueue = {3,2,1};
    int port = 41;
    Message mes{MessageType::TOKEN,port,"Lock",LN,RequestQueue};
    std::string serializedMessage = mes.serializeMessage();
    if(serializedMessage == "TOKEN,41,Lock,0;0;0;0;0,3;2;1"){
        return true;
    } else {
        return false;
    }
}

bool is_serializedProperlyRequest(){
    int port =41;
    int sn = 1;
    Message mes{MessageType::REQUEST,port,sn,"Lock"};
    std::string serializedMessage = mes.serializeMessage();
    if(serializedMessage == "REQUEST,41,1,Lock"){
         return true;
    } else {
        return false;
    }
}


bool is_deserializedProperlyToken() {
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
            return true;
       }else {
           return false;} 
}

bool is_deserializedProperlyRequest() {
    std::string serializedMessage ="REQUEST,41,1,Lock";
    Message mes{serializedMessage};
    if(mes.getMessageType()==MessageType::REQUEST&&
       mes.getPort()==41&&
       mes.getSn()==1&&
       mes.getLock()=="Lock")
       {
            return true;
       } else {
            return false;
       } 

}