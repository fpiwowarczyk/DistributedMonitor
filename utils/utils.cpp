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