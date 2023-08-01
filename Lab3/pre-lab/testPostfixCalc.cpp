//Anna Alberti
//aca5z
//9/12/2021
//name of file: testPostfixCalc.cpp

#include <iostream>
#include <stack>
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
	if(pfc.s.empty()){
	  exit(-1);
	}
	pfc.addition();
	//cout << pfc.s.top();
      }
      else if(token  == "-"){
	//cout << "if == -" << endl;
	//call subtraction method
	if(pfc.s.empty()){
	  exit(-1);
	}
	pfc.subtraction();
	//cout << pfc.s.top()<< endl;

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

