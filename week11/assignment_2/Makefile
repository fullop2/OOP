.SUFFIXES: .cpp .o

OBJECTS = Complex.o Float.o Integer.o testlist.o
TEST_FILE = test.o $(OBJECTS)
CXX = g++
CXXFLAGS = -g
TEST = test

$(TEST) : $(TEST_FILE)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean :
	\rm -rf $(TEST_FILE)
