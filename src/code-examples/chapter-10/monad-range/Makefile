PROGRAM   = main
CXX       = g++
CXXFLAGS  = -g -std=c++17 -Wall -I../../3rd-party/ericniebler/range-v3/include

$(PROGRAM): main.o
	$(CXX) -o $(PROGRAM) main.o -lstdc++fs

.PHONY: clean dist

clean:
	-rm -f *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)


