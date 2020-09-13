#include "utils.h"

template <> void Utils::displayVector(std::vector<int> vector){
    for(unsigned int i=0;i<vector.size();i++){
        std::cout<<"i["+std::to_string(i) +"]:" << vector.at(i) << std::endl;
    }
}

std::vector<std::string> Utils::splitString(const std::string &txt, char ch){
    std::vector<std::string> strs;
    size_t pos = txt.find(ch);
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while (pos != std::string::npos) {
        strs.push_back(txt.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;

        pos = txt.find(ch, initialPos);
    }

    // Add the last one
    strs.push_back(
        txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));
    return strs;
}

std::string Utils::vectorToString(std::vector<int> vec){
    std::string output ="";

    for(int v:vec){
        output += std::to_string(v);
        output += ";";
    }
    output.pop_back(); // Remove last  ";" from string
    return output;
}

std::string Utils::queueToString(std::queue<int> queue){
    std::string output ="";
    if(queue.size()==0){
        return "null";
    }
    std::queue<int> copy_queue =queue;
    while(copy_queue.size()>0){
        output+=std::to_string(copy_queue.front());
        copy_queue.pop();
        output+=";";
    }
    output.pop_back();//Remove last ";" from string
    return output;
}

bool Utils::isInQueue(std::queue<int> queue,int value){
    int item;
    while(queue.size()>0){
        item = queue.front();
        if(item==value) return true;
        queue.pop();
    }

    return false;
}

std::vector<int> Utils::sortVector(std::vector<int> vec){
    std::sort(vec.begin(), vec.end(), [](int a, int b){
        return b>a; 
    });

    return vec;
}
