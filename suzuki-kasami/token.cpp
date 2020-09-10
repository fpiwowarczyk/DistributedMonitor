#include "token.h"


//------------------------ TOKEN

void Token::addRequestNumber(){
    LN.push_back(0);
}

void Token::updateLastRequestNumber(){
    std::cout<<"TODO"<<std::endl;
}

void Token::addToQueue(){

}

void Token::removeFromQueue(){

}

void Token::displayLastRequestNumbers(){
    Utils::displayVector(LN);
}
void Token::displayQueue(){
    Utils::displayVector(requestQueue);
}

