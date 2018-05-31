# Makefile for 'TickyTacky' C++ application

tickytacky : main.o game.o
	g++ -Wall -o main.o game.o
main.o : src/main.cpp
	g++ -Wall -c src/main.cpp
game.o : src/game.cpp
	g++ -Wall -c src/game.cpp
clean :
	rm -f core tickytacky main.o game.o
