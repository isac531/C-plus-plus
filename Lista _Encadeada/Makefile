CXX = g++
CXXFLAGS = -Wall

all: main 

main: main.cpp lista.cpp no.cpp
	$(CXX) $(CXXFLAGS) -o main main.cpp lista.cpp no.cpp

run: main
	./main

clean:
	del -f main
