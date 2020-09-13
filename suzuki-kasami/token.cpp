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
    std::cout<<"Add to queue request:"<<request<<std::endl;
    requestQueue.push(request);
}

int Token::removeFromQueue(){
    int item = requestQueue.front();
    requestQueue.pop();
    return item;
}

void Token::printQueue(){
    std::queue<int> cpy_q = requestQueue;
    std::cout<<"Token Queue:"<<std::endl;
    for(unsigned int i=0;i<requestQueue.size();i++){
        std::cout<<"["<<i<<"]"<<std::to_string(cpy_q.front())<<std::endl;
        cpy_q.pop();
    }
}

void Token::displayLastRequestNumbers(){
    Utils::displayVector(LN);
}

std::vector<int> Token::getLN(){return LN;}

std::queue<int> Token::getRequestQueue(){return requestQueue;}

