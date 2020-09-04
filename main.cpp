#include "./tests/test_monitor.h"
#include <thread>
#include <iostream>
#include<vector>

const std::string TEST = "test";
const std::string MONITOR = "monitor";

int main(int argc,char **argv) {
   
   if(argc<2) {
      std::cout <<"Please pass proper arguments" << std::endl;
      return -1;
   }

   if(argv[1]==MONITOR){
      int port = std::stoi(argv[3]);

      std::vector<int> otherPorts{};
      for(int i =4;i<argc;i++){
         otherPorts.push_back(std::stoi(argv[i]));
      }
      Monitor monitor {port,otherPorts};
   } else if (argv[1]==TEST){
      runMonitorTests();
   }

   return 1;
   
}

