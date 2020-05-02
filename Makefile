CXX = g++
CXXFLAGS = -Wall -g

OBJECTS = main.o game.o board.o

tickytacky : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o tickytacky $(OBJECTS)
game.o : game.h board.h
board.o : board.h

.PHONY : clean
clean :
	rm tickytacky $(OBJECTS)
