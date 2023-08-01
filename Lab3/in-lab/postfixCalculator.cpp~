//Anna Alberti
//aca5z
//9/12/2021
//name of file: postfixCalculator.cpp

#include <iostream>
#include <stack>
#include "postfixCalculator.h"
#include <cstdlib>
#include <string>

using namespace std;

//constructor
postfixCalculator::postfixCalculator(){
  stack<int> s;
}

void postfixCalculator::addition(){
  int x;
  int y;
  x = s.top();
  s.pop();
  y = s.top();
  s.pop();
  int z = x+y;
  s.push(z); //push result back onto the stack
}

void  postfixCalculator::subtraction(){
  int x;
  int y;
 
  x = s.top();
  s.pop();

  y = s.top();
  s.pop();
  int z = y - x;
  s.push(z); //push result back onto stack
}

bool postfixCalculator::empty(){
  if (s.empty()){
    return true;
  } else {
    return false;
}
}
