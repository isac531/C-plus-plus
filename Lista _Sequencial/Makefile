CXX = g++
CXXFLAGS = -Wall

all: main 

main: main.cpp lista.cpp
	$(CXX) $(CXXFLAGS) -o main main.cpp lista.cpp

run: main
	./main

clean:
	del -f main
