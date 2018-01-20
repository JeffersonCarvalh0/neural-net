CXX = g++
CXXFLAGS = -std=c++11 -Wall -I include -g
OBJ = main.o network.o
VPATH = include:src

main : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

main.o : main.cpp network.o

network.o : network.cpp network.h

.PHONY : clean
clean :
	rm main *.o
