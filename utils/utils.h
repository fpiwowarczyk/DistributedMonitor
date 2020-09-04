#ifndef UTILS_H
#define UTILS_H

#include "../message/message.h"
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

class Message;

enum class HelperMessageReceiverOrSender {RECEIVER,SENDER};

class Utils {
    private:
        Utils();

    public:
    
    template <typename T> static void displayVector(std::vector<T> vector);
};


#endif