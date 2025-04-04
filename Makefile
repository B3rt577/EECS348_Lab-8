CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: main

main: main.o matrix.o
	$(CXX) $(CXXFLAGS) -o main main.o matrix.o

main.o: main.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

matrix.o: matrix.cpp matrix.hpp
	$(CXX) $(CXXFLAGS) -c matrix.cpp

clean:
	rm -f *.o main
