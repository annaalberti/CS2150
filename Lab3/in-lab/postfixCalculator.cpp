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

void postfixCalculator::multiplication(){
  int x;
  int y;
  empty();
  x = s.top();
  s.pop();
  empty();
  y = s.top();
  s.pop();
  int z = y*x;
  s.push(z); //push result back onto stack
  
}
void postfixCalculator::division(){
  int x;
  int y;
  empty();
  x = s.top();
  s.pop();
  empty();
  y = s.top();
  s.pop();
  int z = y/x;
  s.push(z); //push result back onto stack
}

void postfixCalculator::negate(){
  int x;
  int z;
  empty();
  x = s.top();
  s.pop();
  z = x * -1;
  s.push(z);
}

void  postfixCalculator::empty(){
  if (s.empty()){
    exit(-1);
  } 
}

