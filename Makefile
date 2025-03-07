CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

LLREC_OBJS := llrec.o llrec-test.o
HEAP_OBJS := heap.o heap-test.o
STACK_OBJS := stack.o stack-test.o

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: $(LLREC_OBJS)
	$(CXX) $(CXXFLAGS) $(LLREC_OBJS) -o llrec-test
llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec-test.cpp
llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec.cpp

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 