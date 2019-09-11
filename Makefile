CXX = g++

TARGET = test

OBJECTS = main.o print.o student_id.o

$(TARGET) : $(OBJECTS) 
	$(CXX) -g -o $(TARGET) $(OBJECTS)
clean : 
	rm -rf $(OBJECTS) $(TARGET)
print.o : print.cpp print.h student_id.h
	$(CXX) -c print.cpp
student_id.o : student_id.cpp student_id.h
	$(CXX) -c student_id.cpp
