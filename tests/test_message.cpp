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
    std::queue<int> requestQueue;
    requestQueue.push(3);
    requestQueue.push(2);
    requestQueue.push(1);
    int port = 41;
    Message mes{MessageType::TOKEN,port,LN,requestQueue};
    std::string serializedMessage = mes.serializeMessage();
    return(serializedMessage == "TOKEN,41,0;0;0;0;0,3;2;1");

}
bool is_serializedProperlyRequest(){
    int port =41;
    int sn = 1;
    Message mes{MessageType::REQUEST,port,sn};
    std::string serializedMessage = mes.serializeMessage();
    return(serializedMessage == "REQUEST,41,1");
}
bool is_deserializedProperlyToken() {
    std::string serializedMessage ="TOKEN,41,0;0;0;0;0,3;2;1";
    Message mes{serializedMessage};
    std::vector<int> LN = {0,0,0,0,0};
    std::queue<int> requestQueue;
    requestQueue.push(3);
    requestQueue.push(2);
    requestQueue.push(1);
    return (mes.getMessageType()==MessageType::TOKEN&&
       mes.getPort()==41&&
       mes.getLN()==LN&&
       mes.getRequestQueue()==requestQueue);

}

bool is_deserializedProperlyRequest() {
    std::string serializedMessage ="REQUEST,41,1";
    Message mes{serializedMessage};
    return(mes.getMessageType()==MessageType::REQUEST&&
       mes.getPort()==41&&
       mes.getSn()==1);
}
