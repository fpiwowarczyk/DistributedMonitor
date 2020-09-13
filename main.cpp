#include "./tests/test_monitor.h"
#include "./tests/test_message.h"
#include "./tests/test_suzuki-kasami.h"
#include "./tests/test_program.h"
#include "./tests/test_token.h"
#include <thread>
#include <iostream>
#include <vector>

//To run example ./a.out auto [1||2||3(one of them)] 
//in three consoles 

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
      runTokenTests();
      runSuzukiKasamiTests();
   }else if(argv[1]==MONITOR_AUTO){
      int numberProgram=std::stoi(argv[2]); 
      runTestProgram(numberProgram);        
   }else {
       std::cout << "Invalid argument: " << argv[1] << std::endl;
    }
   return 1; 
}

