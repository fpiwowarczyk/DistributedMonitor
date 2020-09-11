#include "token.h"


//------------------------ TOKEN

void Token::addRequestNumber(){
    LN.push_back(0);
}

void Token::updateLastRequestNumber(){
    std::cout<<"TODO"<<std::endl;
}

void Token::addToQueue(int request){
    requestQueue.push_back(request);
}

void Token::removeFromQueue(){
    requestQueue.erase(requestQueue.begin());
}

void Token::displayLastRequestNumbers(){
    Utils::displayVector(LN);
}
void Token::displayQueue(){
    Utils::displayVector(requestQueue);
}

