#include "test_program.h"

void runTestProgram(int numberProgram){
    exampleProgram(numberProgram);
}

void exampleProgram(int numberProgram){
    // have 3 programs 41 42 43
    if(numberProgram==1){
        testProgram1();
    } else if (numberProgram==2){
        testProgram2();
    } else if(numberProgram==3){
        testProgram3();
    }
}

void testProgram1(){
    int port = 12345;
    std::vector<int> otherPorts{12346,12347};
    Monitor monitor{port,otherPorts,true}; //program with token
    waitForOthers();
    monitor.enter();// Critical section
    waitForSecs(2);
    monitor.exit();

    monitor.enter();
    waitForSecs(5);
    monitor.exit();

    monitor.enter();
    waitForSecs(5);
    monitor.exit();

    monitor.enter();
    waitForSecs(5);
    monitor.exit();

    monitor.enter();
    waitForSecs(5);
    monitor.exit();

}

void testProgram2(){
    int port = 12346;
    std::vector<int> otherPorts{12345,12347};
    Monitor monitor{port,otherPorts,false};
    waitForOthers();
    monitor.enter();
    waitForSecs(5);
    monitor.exit();

    monitor.enter();
    waitForSecs(5);
    monitor.exit();

    monitor.enter();
    waitForSecs(5);
    monitor.exit();

    monitor.enter();
    waitForSecs(5);
    monitor.exit();
}

void testProgram3(){
    int port =12347;
    std::vector<int> otherPorts{12345,12346};
    Monitor monitor{port,otherPorts,false};
    waitForOthers();
    monitor.enter();
    waitForSecs(5);
    monitor.exit();

    monitor.enter();
    waitForSecs(5);
    monitor.exit();

    monitor.enter();
    waitForSecs(5);
    monitor.exit();

    monitor.enter();
    waitForSecs(5);
    monitor.exit();
}

void waitForOthers(){
    std::cout<<"Press enter if others are ready:"<< std::endl;
    std::cin.get();
    std::cout<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

void waitForSecs(int value){
    std::cout<<"Have Token"<<std::endl;
    for(int i =0;i<=value;i++){
    
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); 
    }
}