#!make -f

CFLAGS=-stdlib=libc++ -std=c++11

demo:  Demo.o
	g++ $(CFLAGS) $^ -o demo

test:  badkan.o
	g++ $(CFLAGS) $^ -o test

%.o: %.cpp
	g++ $(CFLAGS) -c $< -o $@

Demo.o: Demo.cpp Filter_False.h Permutation.h Zip_Longest.h output.h Accumulate.h Cycle.h

badkan.o: badkan.cpp badkan.hpp Filter_False.h Permutation.h Zip_Longest.h output.h Accumulate.h Cycle.h


clean:
	rm -f *.o demo test
