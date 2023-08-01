//Anna Alberti
//aca5z
//11/17/2021

#include "heap.h"
#include "HuffNode.h"
#include <iostream>
#include <vector>
using namespace std;


//I got this code from the slide set 10 slides!
// default constructor
heap::heap() : heap_size(0) {
    myHeap.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<HuffNode*> vec) : heap_size(vec.size()) {
    myHeap = vec;
    myHeap.push_back(myHeap[0]);
    myHeap[0] = 0;
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(HuffNode* n) {
    // a vector push_back will resize as necessary
    myHeap.push_back(n);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    HuffNode* x = myHeap[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x->freq < myHeap[hole/2]->freq); hole /= 2) {
        myHeap[hole] = myHeap[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    myHeap[hole] = x;
}

HuffNode* heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    HuffNode* ret = myHeap[1];
    // move the last inserted position into the root
    myHeap[1] = myHeap[heap_size--];
    // make sure the vector knows that there is one less element
    myHeap.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    HuffNode* x = myHeap[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (myHeap[child+1] < myHeap[child])) {
            child++;
        }
        // if the child is greater than the node...
        if (x->freq > myHeap[child]->freq) {
            myHeap[hole] = myHeap[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    myHeap[hole] = x;
}

HuffNode* heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return myHeap[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    myHeap.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << myHeap[0] << ") ";
    for (int i = 1; i <= heap_size; i++) {
        cout << myHeap[i] << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}

// HuffNode* heap::getFirst(){
//   return myHeap[0];
// }
