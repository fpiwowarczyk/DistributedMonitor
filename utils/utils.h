#ifndef UTILS_H
#define UTILS_H

#include "../message/message.h"
#include "../common/common.h"
#include <chrono>
#include <random>
#include <vector>

class Message;

enum class HelperMessageReceiverOrSender {RECEIVER,SENDER};

class Utils {

    public:
    
        template <typename T> static void displayVector(std::vector<T> vector);

        static long getCurrentTimeStamp();

        static std::string createRequestId(int port,int requestId);
    private:
        Utils();


};


#endif