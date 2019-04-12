CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o vectorr.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
vectorr.o: vectorr.cpp vectorr.h
	$(CXX) $(CXXFLAGS) vectorr.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
