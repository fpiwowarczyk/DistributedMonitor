#include "test_suzuki-kasami.h"

void runSuzukiKasamiTests(){
    getRequestMessages();
    getTokenMessages();
    isRequestMadeProperly();
}

void getRequestMessages(){
    SuzukiKasami suzukiKasami{41,true};
    suzukiKasami.addRequestSite(42);
    suzukiKasami.addRequestSite(43);
    suzukiKasami.addRequestSite(44);
    bool test1,test2,test3;

    Message message {MessageType::REQUEST,42,1};
    suzukiKasami.receiveRequestMessage(message);
    message ={MessageType::REQUEST,43,1};
    suzukiKasami.receiveRequestMessage(message);
    message ={MessageType::REQUEST,44,1};
    suzukiKasami.receiveRequestMessage(message);
    message ={MessageType::REQUEST,42,2};
    suzukiKasami.receiveRequestMessage(message);
    message ={MessageType::REQUEST,42,3};
    suzukiKasami.receiveRequestMessage(message);

    for(std::pair<int,int> rn:suzukiKasami.getRN()){
        if(rn.first==42&&rn.second==3) test1=true;
        if(rn.first==43&&rn.second==1) test2=true;
        if(rn.first==44&&rn.second==1) test3=true;
    }
    if(test1&&test2&&test3){
        std::cout<<"Receiving request messages properly:POSITIVE"<<std::endl;
    } else {
         std::cout<<"Receiving request messages properly:NEGATIVE"<<std::endl;
    }
}

void getTokenMessages(){
    std::vector<int> LN={1,0,0,0,0};
    SuzukiKasami suzukiKasami{41,true};
    suzukiKasami.addRequestSite(42);
    suzukiKasami.addRequestSite(43);
    suzukiKasami.addRequestSite(44);

    std::queue<int> rq;
    rq.push(3);
    rq.push(2);
    rq.push(1);
    Message message {MessageType::TOKEN,42,LN,rq};

    suzukiKasami.receiveTokenMessage(message);

    Token token = suzukiKasami.getToken();
    bool test1;
    if(token.getLN()==LN&&token.getRequestQueue()==rq&&suzukiKasami.getHasToken()==true) test1=true;

    if(test1){
        std::cout<<"Receiving token messages properly:POSITIVE"<<std::endl;
    } else {
        std::cout<<"Receiving token messages properly:NEGATIVE"<<std::endl;
    }
    
}

void isRequestMadeProperly(){
    std::cout<<"Testing making requests"<<std::endl;
    std::vector<int> LN={0,0,0,0};
    SuzukiKasami suzukiKasami{41,true};
    suzukiKasami.addRequestSite(41);
    suzukiKasami.addRequestSite(42);
    suzukiKasami.addRequestSite(43);
    suzukiKasami.addRequestSite(44);

    suzukiKasami.sendRequestMessage();
}