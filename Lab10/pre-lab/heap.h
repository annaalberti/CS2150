//Anna Alberti
//aca5z
//11/17/2021

#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include "HuffNode.h"

class heap {
 public:
    heap();
  heap(vector<HuffNode*> vec);
    ~heap();

    void insert(HuffNode* n);
    HuffNode* findMin();
    HuffNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();
  //HuffNode* getFirst();


    vector<HuffNode*> myHeap;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
  
};
#endif
