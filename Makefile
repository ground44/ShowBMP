src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

all: show
	
CC=g++
CXXFLAGS= -std=c++0x
LDLIBS=-lglfw -lGL -lGLU -lGLEW

debug: CXXFLAGS+= -DDEBUG -g
debug: show

show: $(obj)
	$(CC) -o $@ $^ $(CXXFLAGS) $(LDLIBS)

.PHONY: clean
clean:
	rm -f $(obj) show