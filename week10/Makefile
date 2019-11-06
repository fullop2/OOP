.SUFFIXES = .o .cpp

CXX = g++

OBJECTS =  vehicle.o car.o bike.o

MAIN = main.o

TARGET = test

$(TARGET) : $(MAIN) $(OBJECTS)
	$(CXX) -o $@ $^

clean: 
	\rm -rf $(TARGET) $(MAIN) $(OBJECTS)

main.o : main.cpp car.h bike.h
vehicle.o : vehicle.cpp
car.o : car.cpp
bike.o : bike.cpp
