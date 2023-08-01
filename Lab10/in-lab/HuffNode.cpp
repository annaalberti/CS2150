//Anna Alberti
//10/18/2021
//aca5z

#include <iostream>
#include "HuffNode.h"
using namespace std;

HuffNode::HuffNode(){
  left = NULL;
  right = NULL;
}

HuffNode::HuffNode(char c, int f){
  character = c;
  freq = f;
  left = NULL;
  right = NULL;
}

HuffNode::~HuffNode(){
}
