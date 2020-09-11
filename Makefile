CXX = g++

MESSAGE = ./message/message.cpp ./message/messageType.cpp
MONITOR = ./monitor/monitor.cpp
UTILS = ./utils/utils.cpp
SUZUKI_KASAMI = ./suzuki-kasami/suzuki-kasami.cpp
TOKEN = ./suzuki-kasami/token.cpp
TEST= ./tests/test_monitor.cpp ./tests/test_message.cpp ./tests/test_suzuki-kasami.cpp
MAIN = ./main.cpp

ALL = $(UTILS) $(MESSAGE) $(MONITOR) $(TOKEN) $(SUZUKI_KASAMI) $(TEST) $(MAIN)

#Libraries
LIBS = -lzmq -pthread 
#Flags for g++
CXXFLAGS = -Wall 


main: clean debug 
	$(CXX) $(CXXFLAGS) $(ALL) $(LIBS) 

clean:
	 rm -f *.out

debug:
	echo "Compiling project"
