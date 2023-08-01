//Anna Alberti
//11/28/2021
//aca5z
//this file is for the node class for the graph in topological sort

#ifndef NODE_H
#define NODE_H
#incldue <iostream>
using namespace std;

class node{
 public:
  node();

  string item;
  int indegree;
  node* ptr;
};
#endif
