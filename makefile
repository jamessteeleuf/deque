OBJECTS = tDeque_main.o tDeque.o
TESTS   = testmain.o tDeque.o
CC      = g++
DEBUG   = -g
CFLAGS  = -Wall -c $(DEBUG)
LFLAGS  = -Wall $(DEBUG)

all: tDeque tests

tDeque: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o tDeque

tests: $(TESTS)
	$(CC) $(LFLAGS) $(TESTS) -o tests

testmain.o: testmain.cpp
	$(CC) $(CFLAGS) testmain.cpp

main.o: tDeque_main.cpp
	$(CC) $(CFLAGS) tDeque_main.cpp
	
tDeque.o: tDeque.h tDeque.cpp
	$(CC) $(CFLAGS) tDeque.cpp
