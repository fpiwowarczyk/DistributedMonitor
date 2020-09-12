#ifndef TOKEN_H
#define TOKEN_H
#include "../common/common.h"
#include "../utils/utils.h"
#include<vector>
#include<queue>


class Token{
    public:

        void addRequestNumber();
        void addToQueue(int request);
        void updateToken(Message message);
        int removeFromQueue();
        void displayLastRequestNumbers();


        std::vector<int> getLN();
        std::queue<int> getRequestQueue();
    private :
        std::vector<int> LN;
        std::queue<int> requestQueue;
    };


#endif