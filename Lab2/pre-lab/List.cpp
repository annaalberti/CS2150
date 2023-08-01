#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
//Anna Alberti aca5z
// name of file: List.cpp
// 9/6/2021
List::List(){
  count = 0;
  head = new ListNode();
  tail = new ListNode();
  head->next=tail;
  tail->previous=head;
}

List::~List(){
}

//This below code was given in the pre-lab
// Copy constructor
// Called when the code looks something like List list2 = list1;
// (In other words, it is called when you are trying to construct a **new** list from an existing one)
List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

//How do I implement a destructor?


bool List:: isEmpty() const {
  
  return true;
}

void List::makeEmpty(){
  
}

ListItr List::first() {
  ListItr l1;
  l1.current = head->next;
  return l1;
}

ListItr List:: last()  {
  ListItr l1;
  l1.current = tail->previous;
  return l1;
}

void List::insertAfter(int x, ListItr position){
  ListNode* newListNode = new ListNode();
  newListNode->value = x; //sets the value equal to x input
  newListNode->next = position.current->next; //
  newListNode->previous = position.current->previous; //assign newListNode's pointers to the ones around it
  position.current->next = newListNode;
  newListNode->next->previous = newListNode;
  //the ones around it to ListNode
  
}

void List::insertBefore(int x, ListItr position){
  ListNode* newListNode = new ListNode();
  newListNode->value = x;
  newListNode->previous = position.current->next;
  newListNode->next = position.current->previous;
  position.current->previous = newListNode;
  newListNode->previous->next = newListNode;
}

void List::insertAtTail(int x) {
  ListNode* newListNode = new ListNode();
  newListNode->value = x;
  newListNode->next = tail;
  newListNode->previous = tail->previous;
  tail->previous->next = newListNode;
  tail->previous = newListNode;
  count++;

  
}

ListItr List::find(int x){
  //some sort of iteration through all the nodes?
  //if( current->value == x){
  //  ListItr l1;
  //  l1.current-> //how to access this node?
  // return ListItr; //do I need to have a this.ListItr or something?
  //}
  //else{
  // break;
  //	}
  
  //}
}

void List:: remove(int x){
  //targetListItr = find( x);
  //do something to remove it?
  //targetListItr.current->next->previous = current->previous; //is this right? to take it out of the list?
  
}

int List:: size() const{
  return count;
}

void printList(List& source, bool forward){
  ListItr l1 = source.first();
  if(forward){
    while(!l1.isPastEnd()) {
      cout << l1.retrieve() << " "<<endl;
      l1.moveForward();
    }
  }
  else{ //if !forward
    cout << l1.retrieve() << " "<<endl;
      l1.moveBackward();
  }
}

