# Makefile for 'TickyTacky' C++ application

tickytacky : main.o game.o
	g++ -o main.o game.o
main.o : src/main.cpp
	g++ -c src/main.cpp
game.o : src/game.cpp
	g++ -c src/game.cpp
clean :
	rm core tickytacky main.o game.o
