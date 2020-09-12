#include "test_suzuki-kasami.h"

void runTestSuzukiKasami(){
    getRequestMessages();
}

void getRequestMessages(){
    SuzukiKasami suzukiKasami{41};
    suzukiKasami.addRequestSite(42);
    suzukiKasami.addRequestSite(43);
    suzukiKasami.addRequestSite(44);

    Message message {MessageType::REQUEST,42,1,"lock"};
    suzukiKasami.receiveRequestMessage(message);
    Message message1 {MessageType::REQUEST,43,1,"lock"};
    suzukiKasami.receiveRequestMessage(message1);
    Message message2 {MessageType::REQUEST,44,1,"lock"};
    suzukiKasami.receiveRequestMessage(message2);
    Message message3 {MessageType::REQUEST,42,2,"lock"};
    suzukiKasami.receiveRequestMessage(message3);
    Message message4 {MessageType::REQUEST,42,3,"lock"};
    suzukiKasami.receiveRequestMessage(message4);

    for(std::pair<int,int> rn:suzukiKasami.getRN()){
        std::cout<<"Port["<<rn.first<<"]:"<<rn.second<<std::endl;
    }
}


