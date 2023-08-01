//Anna Alberti
// aca5z
//9/12/2021
//name of file: postfixCalculator.h
#include <iostream>
#include "stack.h"
#include <cstdlib>
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
using namespace std;
#include <string>



class postfixCalculator {
  public:
  stack s;
  
  //Constructor
  postfixCalculator();

  void addition();
  void subtraction();
  void multiplication();
  void division();
  void negate();
  void empty();
};

#endif
