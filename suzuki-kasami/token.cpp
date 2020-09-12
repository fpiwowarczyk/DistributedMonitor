#include "token.h"


//------------------------ TOKEN

void Token::addRequestNumber(){
    LN.push_back(0);
}

void Token::updateLastRequestNumber(){
    std::cout<<"TODO"<<std::endl;
}

void Token::addToQueue(int request){
    requestQueue.push(request);
}

int Token::removeFromQueue(){
    int item = requestQueue.front();
    requestQueue.pop();
    return item;
}

void Token::displayLastRequestNumbers(){
    Utils::displayVector(LN);
}

