CC= g++
CFLAGS= -Wall -c
SOURCES= RK1-Nikulin.cpp Shop.cpp
HEADERS= Shop.hpp
OBJECTS= $(SOURCES:.cpp=.o)
EXECUTABLE= rk1

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $^ -o $@

%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) $< -o $@

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(EXECUTABLE) $(OBJECTS)