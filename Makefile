CXX = g++
CXXFLAGS = -std=c++11 -Wall

OBJECTS = main.o graph.o

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

main.o: main.cpp graph.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

graph.o: graph.cpp graph.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)
