//Anna Alberti
//11/18/2021
//aca5z
//HuffNode object for lab 10

#ifndef HUFFNODE_H
#define HUFFNODE_H

#include<iostream>
using namespace std;


class HuffNode {
 public:
  HuffNode();
  HuffNode(char c, int f);
  ~HuffNode();
  
  char character;
  int freq;
  HuffNode* left;
  HuffNode* right;
  
  
};
#endif
