#include "token.h"


//------------------------ TOKEN

void Token::addRequestNumber(){
    LN.push_back(0);
}

void Token::updateToken(Message message){
    LN = message.getLN();
    requestQueue=message.getRequestQueue();
}

void Token::updateLN(int position){
    LN[position]++;
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

std::vector<int> Token::getLN(){return LN;}

std::queue<int> Token::getRequestQueue(){return requestQueue;}

