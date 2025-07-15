# Makefile for Splitwise-Core-Engine

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
SRC = main.cpp Splitwise.cpp Models.cpp Balancer.cpp utils.cpp
OUT = splitwise

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
