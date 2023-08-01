#include "BinaryNode.h"
#include <string>
using namespace std;

// BinaryNode::BinaryNode(const string& x, BinaryNode* b1, BinaryNode* b2){
//   value = x;
//   left = NULL;
//   right = NULL;
// }

BinaryNode::BinaryNode() {
    value = "?";
    left = NULL;
    right = NULL;
}

BinaryNode::~BinaryNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
}
