#include "./tests/test_monitor.h"
#include "./tests/test_message.h"
#include "./tests/test_suzuki-kasami.h"
#include "./tests/test_program.h"
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
   }else if(argv[1]==MONITOR_AUTO){
      int numberProgram=std::stoi(argv[2]); //RUn as 1 2 3 in console
      runTestProgram(numberProgram);
   }else {
       std::cout << "Invalid argument: " << argv[1] << std::endl;
    }

   return 1; 
}

