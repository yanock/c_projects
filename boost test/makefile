CC=g++
CFLAGS=-c -Wall
DEBUG = -g
LDFLAGS=
SOURCES=boost.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=boost
INCLUDE=-lboost_thread


all: $(SOURCES) $(EXECUTABLE) $(INCLUDE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@




g++ -L/usr/include/boost -lboost_lambda boost_lambda.cpp -o boost_lambda
