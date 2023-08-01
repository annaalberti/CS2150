#Anna Alberti
# 11/28/2021

CXX = clang++ $(CXXFLAGS) $(DOXYGEN)
#DOXYGEN = doxygen -g
CXXFLAGS=-Wall #Enable all warnings
DEBUG= -g

a.out: topological.o middleearth.o
	$(CXX) $(DEBUG) topological.o middleearth.o -o a.out
	doxygen

topological.o: topological.cpp
middleearth.o: middleearth.cpp middleearth.h


.PHONY: clean
clean:
	-rm -f *.o a.out
