CXX = g++

#Add Includes and src 
CXXFLAGS = -Wall -g -Iincludes/ -Isrc
# Tells compiler to look for source code in these directories ma
VPATH = includes:src
RM = rm -f
LDLIBS = -lzmq

PROJDIR := ./
SOURCEDIR := $(PROJDIR)/includes
BUILDDIR := $(PROJDIR)/src

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

