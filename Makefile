CXX = g++

MONITOR = ./monitor/monitor.cpp
UTILS = ./utils/utils.cpp
MAIN = ./main.cpp
#Libraries
LIBS = -lzmq -pthread 
#Flags for g++
CXXFLAGS = -Wall 

ALL = $(UTILS) $(MONITOR) $(MAIN)





main: clean debug 
	$(CXX) $(CXXFLAGS) $(ALL) $(LIBS) -o main

clean:
	 rm -f main 

debug:
	echo "Compiling project"
