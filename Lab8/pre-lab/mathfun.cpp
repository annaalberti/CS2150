//Anna Alberti
//aca5z
//10/31/2021
//mathfun.cpp
// main function for mathlib.s

#include <iostream>
using namespace std;

extern "C" long product (long, long);
extern "C" long power (long, long);


int main(){
  long x;
  long y;
  
  cout << "Enter integer 1: ";
  cin >> x; //will be stored in rdi
  cout << "Enter integer 2: ";
  cin >> y; //will be stored in rsi

  long productanswer = product(x, y); //is this right
  long poweranswer = power(x, y);

  cout << "Product: " << productanswer << endl;
  cout << "Power: " << poweranswer;
  
  return 0;
}
