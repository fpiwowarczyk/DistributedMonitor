#ifndef TOKEN_H
#define TOKEN_H
#include "../common/common.h"
#include "../utils/utils.h"
#include<vector>
#include<queue>


class Token{
    public:

        void updateToken(Message message);

        void addRequestNumber();
        void addToQueue(int request);
        void printQueue();
        int removeFromQueue();

        void updateLN(int position);
        void displayLastRequestNumbers();
        
        std::vector<int> getLN();
        std::queue<int> getRequestQueue();
    private :
        std::vector<int> LN;
        std::queue<int> requestQueue;
    };


#endif