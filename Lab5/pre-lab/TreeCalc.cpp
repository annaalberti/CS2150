// Insert your header information here
//Anna Alberti aca5z 10/3/2021
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <stack>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
  if(tree->left != NULL){
    cleanTree(tree->left);
  }
  if(tree->right != NULL){
    cleanTree(tree->right);
  }
  delete tree;
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
  if (val == "+" || val == "-" || val == "*" || val == "/"){
        TreeNode *newNode = new TreeNode(val);
	//makeTree(newNode); //make a tree with the operator node as root
	newNode->right = expressionStack.top(); //left child is first item
	expressionStack.pop();
	newNode->left = expressionStack.top(); //right child is second item
	expressionStack.pop();
	expressionStack.push(newNode);
  } else{
    TreeNode *newNode = new TreeNode(val);
    expressionStack.push(newNode);
  }
}


// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
  //node, child, child
  if (tree != NULL){
  cout << tree->value << " ";
  //cout << "made it here";
  printPrefix(tree->left);
  printPrefix(tree->right);
  }
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
  //left child, self node, right node
  if (tree !=NULL){
    if (tree->value == "+" || tree->value == "-" || tree->value == "/" || tree->value == "*"){
      cout << "(";
      printInfix(tree->left);
      cout << " " << tree->value << " ";
      printInfix(tree->right);
      cout << ")";
    }
    //cout << "made it here";
  else {
    cout << tree->value;
  }
  }
  
}
//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
  //child, children, node
  if (tree != NULL){
  printPostfix(tree->left);
  printPostfix(tree->right);
  cout << tree->value << " ";
  //cout << "made it here";
    }
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
    //infix calculation
  if (tree == NULL){ //base case
    return 0;
  }
  else if (tree->value == "+"){
      int x = calculate(tree->left);
      int y = calculate(tree->right);
      return x + y;
    }
    else if (tree->value == "-"){
      int x = calculate(tree->left);
      int y = calculate(tree->right);
      return x - y;

    } else if (tree->value == "*"){
      int x = calculate(tree->left);
      int y = calculate(tree->right);
      return x * y;
    } else if (tree->value == "/"){
      int x = calculate(tree->left);
      int y = calculate(tree->right);
      return x/y;
    } else { //if it's a number
      return std::stoi(tree->value);
    }
    }

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
  int calculation  = 0;
  calculation = calculate(expressionStack.top());
  cleanTree(expressionStack.top());
  expressionStack.pop(); //get rid of last value
  return calculation;
  
}
