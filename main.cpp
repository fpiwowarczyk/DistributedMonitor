#include "./tests/test_monitor.h"
#include "./tests/test_message.h"
#include "./tests/test_suzuki-kasami.h"
#include <thread>
#include <iostream>
#include <vector>


/*
*HOW to run 
* Initailly token is on 1 program
* template: ./a.out [function] [your port] [number of program] [first port] [second port] ...
* 1 console: ./a.out monitor 10 1 11 12 13
* 2 console: ./a.out monitor 11 2 10 12 13
* 3 console: ./a.out monitor 12 3 11 10 13
* 4 console: ./a.out monitor 13 4 11 12 10
*/
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
      runTestSuzukiKasami();
   } else if(argv[1] == MONITOR_MANUAL){
      int port = std::stoi(argv[2]);
      std::vector<int> otherPorts{};

      for(int i=3;i<argc;i++){
         otherPorts.push_back(std::stoi(argv[i]));
      }
      Monitor monitor{port, otherPorts};
      
      std::cout<<"Press enter if others are ready:"<< std::endl;
      std::cin.get();
      std::cout<<std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(2000));
      monitor.enter("Lock1"); // Try to enter lock
   } else if(argv[1]==MONITOR_AUTO){
      std::cout<< "Right now nothing"<<std::endl;
    } else {
       std::cout << "Invalid argument: " << argv[1] << std::endl;
    }

   return 1; 
}

