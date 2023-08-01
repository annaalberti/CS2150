//Anna Alberti aca 5z
//name of file: stack.h
//9/13/2021

#include <iostream>
#include <cstdlib>
#include "stack.h"
#include "List.h" //implementing the stack using my doubly linked list from lab 2
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

//constructor
stack::stack(){
  s = List(); //the stack is technically a linked list
}

//destructor
stack::~stack(){
  s.makeEmpty();
}

void stack::push(int e){
  s.insertBefore(e, s.first()); //head is the top of the stack
  // this will set ListItr to the head and insert before the head, so the top position of the stack
}

int stack:: top(){
  if (empty()){ //need to check if empty before
    exit(-1);
      }
  return s.returnFirstValue(); //returns the first value at the head (top value of stack)
}

void stack::pop(){
  if (empty()){ //need to check if empty before
    exit(-1);
      }
  s.remove(s.returnFirstValue()); //remove the first value at the head (top value of stack)
  
}
  
bool stack::empty(){
  if(s.size() == 0){
    return true;
      }
  else {
    return false;
      }
}
