#Anna Alberti
# 10/17/2021

CXX = clang++ $(CXXFLAGS)
CXXFLAGS=-Wall #Enable all warnings
DEBUG= -g

a.out: hashTable.o wordPuzzle.o timer.o
	$(CXX) $(DEBUG) hashTable.o wordPuzzle.o timer.o -o a.out

hashTable.o: hashTable.cpp hashTable.h
timer.o: timer.cpp timer.h timer_test.cpp
wordPuzzle.o: wordPuzzle.cpp timer.cpp timer.h timer_test.cpp hashTable.cpp hashTable.h

.PHONY: clean
clean:
	-rm -f *.o a.out
