	//Anna Alberti
	//aca5z 11/14/2021
	//name of file: threexplusone.s
#include <iostream>
using namespace std;
#include "timer.h"

extern "C" long threexplusone (long);


int main(){
  //timer t;
  
  long x; //value for subroutine
  double n; //num of times to run the subroutine

  cout << "Enter a number: ";
  cin >> x; //will be stored in rdi
  cout << "Enter interations of subroutine: ";
  cin >> n;

  //double sum = 0;
  for( int i=0; i<=n; i++){
    //t.start();
    threexplusone(x);
    // t.stop();
    //double time = t.getTime();
    //sum+=time;
  }

  long answer = threexplusone(x);
  cout << answer<< endl;

  //cout << "average time: " << sum/n << endl;

  
  return 0;
}
