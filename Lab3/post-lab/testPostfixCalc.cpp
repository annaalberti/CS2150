//Anna Alberti
//aca5z
//9/12/2021
//name of file: testPostfixCalc.cpp

#include <iostream>
#include "stack.h"
#include <string>
#include "postfixCalculator.h"
#include <cstdlib>
using namespace std;


int main(){
  postfixCalculator pfc;
  string token;
  while(cin >> token){
      if(token  == "+" ){
	//call addition method
	//cout << "if == +" << endl;
	pfc.addition();
	//cout << pfc.s.top();
      }
      else if(token  == "-"){
	//cout << "if == -" << endl;
	//call subtraction method
	pfc.subtraction();
	//cout << pfc.s.top()<< endl;

      }
      else if(token == "/"){
	pfc.division();
	
      }
      else if(token == "*"){
	  pfc.multiplication();
	}
      else if(token == "~"){
	pfc.negate();
      }
      else { // this means it is an integer
	//cout << "integer part" << endl;
	pfc.s.push(std::stoi(token)); //put onto the stack
      	//cout << pfc.s.top()<< endl;

      }
  }
      //cout << "outside of while loop" << endl;
  cout << pfc.s.top();
}

