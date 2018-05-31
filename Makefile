# Makefile for 'TickyTacky' C++ application

APP  := tickytacky
SRCS := $(wildcard src/*.cpp)
OBJS  = $(patsubst src/%.cpp,%.o,$(SRCS))

$(APP) : $(OBJS)
	g++ -Wall -lc -lstdc++ -o $@ $(OBJS)

$(OBJS) : %.o : src/%.cpp
	g++ -o $@ -c $<

clean :
	rm -f core $(OBJS) $(APP)
