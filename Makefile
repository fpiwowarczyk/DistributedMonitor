CXX = g++

MESSAGE = ./message/message.cpp
MONITOR = ./monitor/monitor.cpp
UTILS = ./utils/utils.cpp
RICART-AGRAWALA= ./ricart-agrawala/ricart-agrawala.h
TEST= ./tests/test_monitor.cpp
MAIN = ./main.cpp

ALL = $(UTILS) $(MESSAGE) $(MONITOR) $(RICART-AGRAWALA) $(TEST) $(MAIN)

#Libraries
LIBS = -lzmq -pthread 
#Flags for g++
CXXFLAGS = -Wall 


main: clean debug 
	$(CXX) $(CXXFLAGS) $(ALL) $(LIBS) 

clean:
	 rm -f main 

debug:
	echo "Compiling project"
