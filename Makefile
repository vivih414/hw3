CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec.o llrec-test.o circuit.o gate.o
	$(CXX) $(CXXFLAGS) -o llrec-test llrec.o llrec-test.o circuit.o gate.o

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 