#Anna Alberti
# 10/4/2021

CXX = clang++ 
CXXFLAGS=-Wall -O2 #Enable all warnings

a.out: BSTPathTest.o BinaryNode.o BinarySearchTree.o
	$(CXX) $(CXXFLAGS) BSTPathTest.o BinaryNode.o BinarySearchTree.o -o a.out

BSTPathTest.o: BSTPathTest.cpp BinaryNode.h BinarySearchTree.h
	$(CXX) -c BSTPathTest.cpp
BinaryNode.o: BinaryNode.cpp BinaryNode.h
	$(CXX) -c BinaryNode.cpp
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h BinaryNode.h
	$(CXX) -c BinarySearchTree.cpp


.PHONY: clean
clean:
	-rm -f *.o a.out
