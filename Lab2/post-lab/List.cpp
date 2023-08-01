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
  makeEmpty();
  delete head;
  head = NULL;
  delete tail;
  tail = NULL;
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


bool List:: isEmpty() const {
  if(count==0){
    return true;
  }
  else{
    return false;
  }
}

void List::makeEmpty(){
  ListItr l1 = (*this).first(); //self dereferencing
  ListNode* tempListNode = (l1.current)->next; //temporary pointer point one ahead
  while(!l1.isPastEnd()){
    //resetting tail and head
    l1.current->previous->next = l1.current->next;
    l1.current->next->previous = l1.current->previous;
    delete l1.current;
    l1.current = tempListNode; //resetting bc just deleted
    tempListNode = tempListNode->next;
    
  }
  count = 0;
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
  //code given in class
  //make new listnode and set value
  ListNode* newListNode = new ListNode();
  newListNode->value=x;
  //reassign pointers
  newListNode->next = position.current->next;
  newListNode->previous = position.current;
  position.current->next->previous=newListNode;
  position.current->next = newListNode;
  count++; //increase count 
  
}

void List::insertBefore(int x, ListItr position){
  //make new listnode and set value
  ListNode* newListNode = new ListNode();
  newListNode->value = x;
  //reassign pointers
  newListNode->previous = position.current->previous;
  newListNode->next = position.current;

  position.current->previous->next = newListNode;
  position.current->previous = newListNode;
  //increase count by 1
  count++;
}

void List::insertAtTail(int x) {
  ListNode* newListNode = new ListNode();
  newListNode->value = x;

  newListNode->previous = tail->previous;
  newListNode->next = tail;

  tail->previous->next = newListNode;
  tail->previous = newListNode;
  count++;

  
}

ListItr List::find(int x){
  //some sort of iteration through all the nodes?
  ListItr l1;
  l1.current=head->next; //sets l1 to the first node in the list
  while(!l1.isPastEnd()) {
    if(l1.current->value == x){ //if the node that current points to has the same
      return l1;            //as x, then return the ListItr
    }
    else{ //if not,
      l1.moveForward(); //move to the next one and check
    }

  }
  return l1; //need to return a ListItr no matter what?
}


void List:: remove(int x){
  ListItr l1 = find(x);
  l1.current->previous->next = l1.current->next;
  l1.current->next->previous = l1.current->previous;//changing pointers to remove the node that l1 points to
  delete l1.current;
}

int List:: size() const{
  return count;
}

void printList(List& source, bool forward){
  if(forward){
    ListItr l1 = source.first();
    while(!l1.isPastEnd()) {
      cout << l1.retrieve() << " ";
      l1.moveForward();
    }
  }
  else { //if !forward
    ListItr l1 = source.last();
    while(!l1.isPastBeginning()){
      cout << l1.retrieve() << " ";
      l1.moveBackward();
    }
  }
    cout << endl;
}

