#Anna Alberti
# 11/28/2021

CXX = clang++ $(CXXFLAGS) $(DOXYGEN)
#DOXYGEN = doxygen -g
CXXFLAGS=-Wall -O2 #Enable all warnings
DEBUG= -g

a.out: traveling-skeleton.o middleearth.o
	$(CXX) $(DEBUG) traveling-skeleton.o middleearth.o -o a.out
	doxygen

traveling-skeleton.o: traveling-skeleton.cpp
middleearth.o: middleearth.cpp middleearth.h


.PHONY: clean
clean:
	-rm -f *.o a.out
