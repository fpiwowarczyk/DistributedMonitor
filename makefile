CXX = g++
CXXFLAGS = -Wall -g
RM = rm -f
LDLIBS = -lzmq

TARGET = main kons

all:$(TARGET)
	@true 

main: main.o utils.o
	$(CXX) $(CXXFLAGS) -o main main.o utils.o $(LDLIBS)

kons: kons.o utils.o
	$(CXX) $(CXXFLAGS) -o kons kons.o utils.o $(LDLIBS)

utils: utils.o
	$(CXX) $(CXXFLAGS) -c utils.o $(LDLIBS)
clean:
	$(RM) *.o main kons