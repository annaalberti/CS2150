//Anna Alberti
// aca5z
// 10/6/2021
#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
  //insert stuff from BST
  //then call balance method, and it will balance going up!
  insert(x,root);
}

void AVLTree::insert(const string& x, AVLNode*& curNode){
  if(curNode == NULL){ //wanna insert here
    curNode = new AVLNode();
    curNode->value = x;
    //curNode->left = NULL;
    //curNode->right = NULL;
  } else if( x < curNode->value){
          insert(x, curNode->left);
      curNode->height = 1 + max(height(curNode->left), height(curNode->right));
      } else if (x>curNode->value){
          insert(x, curNode->right);
      curNode->height = 1 + max(height(curNode->left), height(curNode->right));
    
  } else {
    ;
  }
  balance(curNode);
  //update the height
}
  

	     
// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}
//SAME PATHTO AS BST IN-LAB
// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
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

string AVLTree::pathTo(const string& x,  AVLNode * const curNode) const{ //helper method
  if(curNode == NULL){
    return "";
  }
  else if(curNode->value == x){
    return x;
  } else if (x < curNode->value){
	return curNode->value + " " + pathTo(x, curNode->left); //call it on the left part 
  } else { //going right is the only option left
	return curNode->value + " " + pathTo(x, curNode->right); //call it on the right part
  }
}
//SAME FIND AS BST IN-LAB
// find determines whether or not x exists in the tree.
bool  AVLTree::find(const string& x) const { //i changed this to void bc of helper method
    // YOUR IMPLEMENTATION GOES HERE
   return find(x, root); //call helper method with root
}
//private helper method
bool AVLTree::find( const string& x,  AVLNode* const curNode) const{
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
//SAME NUMNODES AS THE BST IN-LAB
// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const { 
    // YOUR IMPLEMENTATION GOES HERE
  return numNodes(root);
}

int AVLTree::numNodes(AVLNode* curNode) const {
  if (curNode == NULL){
    return 0;
  }
  return numNodes(curNode->left)+ numNodes(curNode->right) +1;
}

// min finds the str

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  // if( n!=NULL){
  //   int nodeBF = getBalanceFactor(n);   
  // }
  //call recursion
  //then do something
  if (height(n->right) - height(n->left) == 2){ //left single rotation, will never be greater than 2
    if (height(n->right->right) - height(n->right->left) < 0 ) { //left-right double rotation, negative so rotate right
      n->right = rotateRight(n->right);
    }
        //perform a left rotation
    n = rotateLeft(n);
  } else if (height(n->right) - height(n->left) == -2){ //right single rotation
    if (height(n->left->right) - height(n->left->left) > 0 ) { //right-left double rotation, this is positive, so go left
      n->left = rotateLeft(n->left);
    }
    //perform a right rotation
    n=rotateRight(n);
  }
}
//private helper method for calculating the balance factor of each node
// int AVLTree::getBalanceFactor(const AVLNode* n)const {
//     if (n == NULL){
//       return 0;
//    }
//     //else if (n->left == NULL){ //check if only right tree exists
//    //    if (n->right != NULL){
//    //     return n->right->height;
//    //   }
//    //    return 0;
//    // } else if (n->right== NULL){ //check if only left tree exists
//    //   if (n->left != NULL){
//    //     return n->left->height;
//    //   }
//    //   return 0;
//    // }
//    // else{
//   return height(n->right) - height(n->left);
//      //}
// }

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode* finalRightChild = n->right;
  AVLNode* tempNode1 = n->right->left;
  finalRightChild->left = n;
  n->right = tempNode1;


  finalRightChild->height = 1 + max(height(finalRightChild->left), height(finalRightChild->right));
  //recalculate height
  n->height = 1 + max(height(n->left), height(n->right));
  return finalRightChild;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
  AVLNode* finalLeftChild = n->left;
  AVLNode* tempNode1 = n->left->right;
  finalLeftChild->right = n;
  n->left = tempNode1;

  finalLeftChild->height = 1 + max(height(finalLeftChild->left), height(finalLeftChild->right));

  
  //recalculate height
  n->height = 1 + max(height(n->left), height(n->right));
  //n->right stays the same?
  return finalLeftChild;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
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

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
