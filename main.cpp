#include "./tests/test_monitor.h"
#include "./tests/test_message.h"
#include <thread>
#include <iostream>
#include <vector>

const std::string TEST = "test";
const std::string MONITOR_MANUAL = "monitor-m";
const std::string MONITOR_AUTO = "auto";

int main(int argc,char **argv) {
   
   if(argc<2) {
      std::cout <<"Please pass proper arguments" << std::endl;
      return -1;
   }

   if (argv[1] == TEST){
      runMessageTests();
      runMonitorTests();
   } else if(argv[1] == MONITOR_MANUAL){
      int port = std::stoi(argv[2]);
      std::vector<int> otherPorts{};

      for(int i=3;i<argc;i++){
         otherPorts.push_back(std::stoi(argv[i]));
      }
      Monitor monitor{port, otherPorts};
      
      std::cout<<"Press enter if others are ready:"<< std::endl;
      std::cin.get();
      monitor.wait();
   } else if(argv[1]==MONITOR_AUTO){
      if(std::stoi(argv[2])==1){ // For 1 console 
         int port = 40;
         std::vector<int> otherPorts{41,42,43};
         Monitor monitor{port, otherPorts};
         std::cout<<"Press enter if others are ready:"<< std::endl;
         std::cin.get();
      } else if(std::stoi(argv[2])==2){ // For 2 console 
         int port = 41;
         std::vector<int> otherPorts{40,42,43};
         Monitor monitor{port, otherPorts};
         std::cout<<"Press enter if others are ready:"<< std::endl;
         std::cin.get();
      } else if(std::stoi(argv[2])==3){ // For 3 console 
         int port = 42;
         std::vector<int> otherPorts{41,40,43};
         Monitor monitor{port, otherPorts};
         std::cout<<"Press enter if others are ready:"<< std::endl;
         std::cin.get();
      } else if(std::stoi(argv[2])==4){ // For 4 console 
         int port = 43;
         std::vector<int> otherPorts{41,42,40};
         Monitor monitor{port, otherPorts};
         std::cout<<"Press enter if others are ready:"<< std::endl;
         std::cin.get();
      }
   }

   return 1;
   
}

