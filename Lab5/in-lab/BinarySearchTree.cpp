#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>
using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = NULL;
    //path = "";
}

BinarySearchTree::~BinarySearchTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there.
void BinarySearchTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  //call my helper insert
  if (find(x)==false){ //if it's not already in there
    //cout << "(insert method) root: " << root << endl;
    insert(x, root);
  }else{
    ;
  }
  
}

void BinarySearchTree::insert(const string& x, BinaryNode*& curNode) {
  if (curNode == NULL){ //this is where it is actually inserting
    curNode = new BinaryNode();
    curNode->value = x;
    curNode->left = NULL;
    curNode->right = NULL;
    //cout << "(insert) just inserted here: " << x <<  endl;
    //cout << "(insert) the new node is: " << curNode << endl;
    //printTree();
  } else if (x < curNode->value){
    if (curNode->left == NULL){
      //BinaryNode * insertNode = new BinaryNode(x, NULL, NULL);
      BinaryNode* insertNode = new BinaryNode();
      insertNode->value = x;
      curNode->left= insertNode;
      //printTree();
      //cout << "going left!" << endl;
    } else{
      insert(x, curNode->left);
    }
  } else if ( x >curNode->value){
    if (curNode->right == NULL){
      //BinaryNode * insertNode = new BinaryNode(x, NULL, NULL);
      BinaryNode* insertNode = new BinaryNode();
      insertNode->value = x;
      curNode->right= insertNode;
      //cout << "going right!" << endl;
    } else{
      insert(x, curNode->right);
    }
  } else{
    ; //duplicate ... do nothing
  }
}

// remove finds x's position in the tree and removes it.
void BinarySearchTree::remove(const string& x) {
    root = remove(root, x);
}

// private helper for remove to allow recursion over different nodes. returns
// a BinaryNode* that is assigned to the original node.
BinaryNode* BinarySearchTree::remove(BinaryNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            // just delete it :)
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // single child (right)
            // remove current node and return right child node for parent
            BinaryNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // single child (left)
            // remove current node and return left child node for parent
            BinaryNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children
            // replace current node with right child node's minimum, then remove that node
            string value = min(n->right);
            n->value = value;
            n->right = remove(n->right, value);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }
    return n;
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string BinarySearchTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  if (root == NULL){
    return "";
  }
  else if (find(x) == true){
  return pathTo(x, root);
  }
  else {
    return "";
  }
}

string BinarySearchTree::pathTo(const string& x,  BinaryNode * const curNode) const{ //helper method
  //string path = "";
  if(curNode == NULL){
  //  cout << "empty path" << endl;
  // path+= "";
    return "";
  }
  else if(curNode->value == x){
    return x;
  } else if (x < curNode->value){
    //path += curNode->value  + " ";
	return curNode->value + " " + pathTo(x, curNode->left); //call it on the left part 
       //cout << "path: " << path << endl;
  } else { //going right is the only option left
    //path += curNode->value  + " ";
	return curNode->value + " " + pathTo(x, curNode->right); //call it on the right part
	//cout << "path: " << path << endl;
  }
}
  
// find determines whether or not x exists in the tree.
bool  BinarySearchTree::find(const string& x) const { //i changed this to void bc of helper method
    // YOUR IMPLEMENTATION GOES HERE
   return find(x, root); //call helper method with root
}
//private helper method
bool BinarySearchTree::find( const string& x,  BinaryNode* const curNode) const{
  //cout << "(find) the root is: " << root << endl;
  if (curNode ==NULL){  //we've run off the bottom
    //cout << "(find method) curNode is null" << endl;
    //cout << "curNode value: " << curNode->value << endl;
    return false;
    }
  else if (x < curNode->value){
    return find(x, curNode->left); //search the left tree for it
  } else if ( x > curNode->value){
    return find(x, curNode->right);
} else if (x == curNode->value){
    return true; //matched
  } else{ //not in the tree
    return false;
  }
}


// numNodes returns the total number of nodes in the tree.
int BinarySearchTree::numNodes() const { 
    // YOUR IMPLEMENTATION GOES HERE
  return numNodes(root);
  //return 100;
}

int BinarySearchTree::numNodes(BinaryNode* curNode) const {
  if (curNode == NULL){
    return 0;
  }
  return numNodes(curNode->left)+ numNodes(curNode->right) +1;
  //return 100;
}

// min finds the string with the smallest value in a subtree.
string BinarySearchTree::min(BinaryNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

void BinarySearchTree::printTree() {
    printTree(root, NULL, false);
}

// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}
