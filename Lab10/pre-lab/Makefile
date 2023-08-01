#Anna Alberti
# 11/15/2021

CXX = clang++ $(CXXFLAGS)
CXXFLAGS=-Wall #Enable all warnings
DEBUG= -g

a.out: heap.o HuffNode.o huffmanenc.o
	$(CXX) $(DEBUG) heap.o HuffNode.o huffmanenc.o -o a.out

heap.o: heap.h heap.cpp
HuffNode.o: HuffNode.h HuffNode.cpp
huffmanenc.o: huffmanenc.cpp


.PHONY: clean
clean:
	-rm -f *.o a.out
