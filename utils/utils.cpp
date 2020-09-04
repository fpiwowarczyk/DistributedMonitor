#include "utils.h"

template <> void Utils::displayVector(std::vector<int> vector){
    for(unsigned int i=0;i<vector.size();i++){
        std::cout<<"i["+std::to_string(i) +"]:" << vector.at(i) << std::endl;
    }
}

// template <>
// void Utils::displayVector(std::vector<std::pair<long, Message>> vector){
//   for (int i = 0; i < vector.size(); i++) {
//     std::cout << "[" + std::to_string(i) + "]:" << std::endl;
//     std::cout << "{" << std::endl
//               << vector.at(i).second << std::endl
//               << "}" << std::endl;
//   }
// }