.SUFFIXES: .cpp .o

CXX = g++
OBJECTS = smart_obj.o shared_ref.o weak_pointer.o student.o human.o
MAIN = test.o $(OBJECTS)

TARGET = test

$(TARGET) : $(MAIN)
	$(CXX) -o $@ $^

clean : 
	rm -rf $(TARGET) $(MAIN)
test.o : test.cpp shared_ref.h weak_pointer.h 

smart_obj.o : smart_obj.cpp 

shared_ref.o : shared_ref.cpp smart_obj.h

weak_pointer.o : weak_pointer.cpp shared_ref.h

student.o : student.cpp human.h

human.o : human.cpp



