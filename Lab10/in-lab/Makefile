#Anna Alberti
# 11/15/2021

CXX = clang++ $(CXXFLAGS)
CXXFLAGS=-Wall #Enable all warnings
DEBUG= -g

a.out: inlab.o
	$(CXX) $(DEBUG) inlab.o -o a.out

inlab.o: inlab.cpp



.PHONY: clean
clean:
	-rm -f *.o a.out
