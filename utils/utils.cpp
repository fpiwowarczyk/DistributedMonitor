#include "utils.h"

template <> void Utils::displayVector(std::vector<int> vector){
    for(unsigned int i=0;i<vector.size();i++){
        std::cout<<"i["+std::to_string(i) +"]:" << vector.at(i) << std::endl;
    }
}

long Utils::getCurrentTimeStamp(){
    return std::chrono::milliseconds(std::time(NULL)).count();
}

std::string Utils::createRequestId(int port, int requestId){
    std::string s_port = std::to_string(port);
    std::string s_requestId = std::to_string(requestId);
    return std::string(s_port+"_"+s_requestId);
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