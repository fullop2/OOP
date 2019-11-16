.SUFFIXES : .cpp .o

CXX = g++

vec : vec.o
	$(CXX) -o $@ $^
map : map.o
	$(CXX) -o $@ $^

clean :
	\rm -rf vec map vec.o map.o
vec.o : vec.cpp
map.o : map.cpp
