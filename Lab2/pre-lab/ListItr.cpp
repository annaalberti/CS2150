#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
//Anna Alberti aca5z
// name of file: ListItr.cpp
// 9/6/2021
//Constructors
ListItr::ListItr(){
  ListNode* current;
  
}

ListItr::ListItr(ListNode* theNode){
  current = theNode;
}

bool ListItr::isPastEnd() const {
  if (current->next == NULL ){
    return true;
  }
  else{
    return false;
}
}
bool ListItr::isPastBeginning()const {
  if (current->previous == NULL ){
    return true;
  }
  else{
    return false;
  }
}

void ListItr::moveForward(){
  if(!isPastEnd()){
    current=current->next; //how to make a pointer equal point to the thing that another pointer points to?? 
    }
}

void ListItr::moveBackward(){
  if(!isPastBeginning()){
  current = current->previous;
  }
}

int ListItr::retrieve()const{ 
  return current->value; //is this how i would access the listnode's value since current points to the value of the listnode?
} 
