//Anna Alberti aca5z
// 9/19/2021
//name of file: prelab4.cpp

#include <iostream>
#include<math.h>
#include <climits>
using namespace std;

void sizeOfTest(){ //should i use the stuff on <climits>?
  cout << "Size of int: " << sizeof(int) << endl;
  cout  << "Size of unsigned int: " << sizeof(unsigned int) << endl;
  cout << "Size of float: " << sizeof(float) << endl;
  cout << "Size of double: " << sizeof(double) << endl;
  cout << "Size of char: " << sizeof(char) << endl;
  cout << "Size of bool: " << sizeof(bool) << endl;
  cout << "Size of int*: " << sizeof(int*) << endl;
  cout << "Size of char*: " << sizeof(char*) << endl;
  cout << "Size of double*: " << sizeof(double*) << endl;
}

void overflow(){
  unsigned int x = UINT_MAX;
  cout<< x << " + 1 = " << x+1 << endl;
}

void outputBinary(unsigned int x){
  string binary = "";
  for(int i=31; i>= 0; i--){
    //print out tests bc i was having errors but fixed it!
    //cout << "2 to the " << i << endl;
    //cout << x << " - " << pow(2.0,i) << " = " << x-pow(2.0, i) << endl;
    if(x-pow(2.0, i) < 0){
      binary += "0";
      //cout << binary<<endl;
    }
    else if(x - pow(2.0,i) >= 0){
      binary += "1";
      x = x - pow(2.0,i);
      //cout << binary<<endl;
    }
    if ((i)%4 == 0){
      binary += " ";
    }
    //cout << "--------------" << endl;
  }
  cout << binary << endl;
}

int main(){
  int x;
  cin >> x;
  sizeOfTest();
  overflow();
  outputBinary(x);
  return 0;
  
}

