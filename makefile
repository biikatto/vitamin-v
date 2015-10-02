CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lncurses
SOURCES=src/main.cpp src/pattern.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=build/vitamin-v

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

run: all
	./build/vitamin-v

clean:
	rm build/*
