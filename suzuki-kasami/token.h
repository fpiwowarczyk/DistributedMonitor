#ifndef TOKEN_H
#define TOKEN_H
#include "../common/common.h"
#include "../utils/utils.h"
#include<vector>


class Token{
    public:
        std::vector<int> LN;
        std::vector<int> requestQueue;
        void addRequestNumber();
        void addToQueue(int request);
        void updateLastRequestNumber();
        void removeFromQueue();
        void displayLastRequestNumbers();
        void displayQueue();
    };


#endif