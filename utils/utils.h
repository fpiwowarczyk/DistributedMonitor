#ifndef UTILS_H
#define UTILS_H


#include "../message/message.h"
#include "../common/common.h"
#include <algorithm>
#include <array>
#include <functional>
#include <chrono>
#include <random>
#include <vector>
#include <queue>


class Utils {

    public:
        template <typename T> static void displayVector(std::vector<T> vector);

        static std::vector<int> sortVector(std::vector<int> vec);

        static std::string vectorToString(std::vector<int> vec);

        static std::vector<std::string> splitString(const std::string &txt, char ch);

        static std::string queueToString(std::queue<int> queue);

        static bool isInQueue(std::queue<int> queue,int value);
    
    private:
};


#endif