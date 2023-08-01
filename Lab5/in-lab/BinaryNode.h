#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <string>
using namespace std;

class BinaryNode {
    BinaryNode();
  //BinaryNode(const string& x, BinaryNode* b1, BinaryNode* b2); //new constructor
    ~BinaryNode();

    string value;
    BinaryNode* left;
    BinaryNode* right;

    friend class BinarySearchTree;
};

#endif
