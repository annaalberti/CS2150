//Anna Alberti
//aca5z
//9/20/2021
//name of file: bitCounter.cpp

using namespace std;
#include <iostream>
#include <math.h>
#include <string>
#include <cctype>
#include <cstdlib>


int numOfOnes(int n){ //returns number of ones in binary representation for n
  //base case
  int ones;
  if (n == 1){
    return 1;
  }
  if(n % 2 ==0){ //if n is even
    return numOfOnes(n/2);
  }
  else if (n%2 != 0){ //if n is odd
    return numOfOnes((n-1)/2)+1; //floor(n/2)
  }
}

string baseConverter(string number, int startBase, int endBase){
  int length = number.length();
  int converted = 0;
  int i = 0;
  for(int k = length-1; k >= 0; k--){ //for index of string
    if (isdigit(number[k])){ //if it is a number
      int multiplier = number[k] - 48;
      //cout << "this is what u mult by : "<< pow(startBase, i) << endl;
      converted += multiplier * pow(startBase, i);
      i++;
    }
    else if(!isdigit(number[k])){
      int multiplier = number[k] - 'A' + 10;  //double digit number the char reprepresents
      converted += multiplier * pow(startBase, i);
      i++;
    }
  }
  //cout << "converted after base10: "<< converted << endl;


  int startExp;
  string final = "";
  
  int n = 0;
  while (converted - pow(endBase, n) >  0){
    n++;
    }

  startExp = n-1;
  //cout << "start exp: " << startExp << endl;
  while(startExp >= 0){
    int fitsCounter = 0; 
  //cout << converted << " - "<< pow(endBase,startExp) << " = " <<endl;
    //cout << "starting converted is : " << converted << endl;
    while(converted-pow(endBase,startExp) >= 0){ //for how many times it can fit
      converted -= pow(endBase,startExp);
      //cout << "converted is : " << converted << endl;
       fitsCounter++;
    }
    //cout << "how many times 3 to the " << startExp << " fits: " << fitsCounter<<endl;
    startExp--;
    //cout << "fits counter: "<< fitsCounter<<endl;
    if (fitsCounter > 9){ //represent with a char
      fitsCounter = fitsCounter - 10 + 'A'; //main issue how to convert int to char letter
      char charCounter = (char)fitsCounter;
      final += charCounter;
    } else{
    final += std::to_string(fitsCounter);
    }
    //cout << "the final is: " << final << endl;
  }
  


  
  // else if(endBase > 10){ //consider letters
  //   int n = 0;
  // while (converted - pow(endBase, n) >  0){
  //   n++;
  //   }

  // startExp = n-1;
  // while(startExp >= 0){
  //   int fitsCounter = 0; 
  // while(converted-pow(endBase,startExp) >= 0){ //for how many times it can fit
  //     converted -= pow(endBase,startExp);
  //     cout << "converted is : " << converted << endl;
  //      fitsCounter++;
  //   }
  //   startExp--;
  //   if(fitsCounter > 9){
  //     fitsCounter = 
  //   }
  //   final += std::to_string(fitsCounter);
  //   cout << "the final is: " << final << endl;
  // }
  // }
  return final;
  // //converting from startbase to base 10
  // int length = number.length();
  // int base10;
  // for (int i = length + 1; i >= 0 ; i--){ //digits
  //   int multiplier =  number[i];
  //   for(int i = 0; i >= length; i++){ //exponents
  //     base10 += multiplier * pow(startBase, i); //accumlate these values
  //   }
  // }
  // int startExp;
  // for(int i=0; base10-pow(endBase, i) < 0; i++){
  //   startExp = i;
  // }
  // //base 11 and above will return something with letters too
  // //what in the world??????
  // //converting from base 10 to radix
  // vector<int> final;
  // for(int k = startExp; k==0; k--){
  //   //how to check how many times it fits?
  //   int fits;
  //   for(int i =1; base10-i*pow(endBase, k) < 0; i++){
  //     fits++;
  //   }
  //   final.push_back(fits);
  //   //
  //   base10 -= fits*pow(endBase, k);
  // }
  // string print;
  // for(int i = 0; i < final.size()+1; i++){
  //   print+= final[i];
  // }
  // return print;
  
  //convert to base 10
  //get each place position and multiply by startBase^i until i= last place position  using pow()?

  //convert to radix
  
  //get each place position and multiply by endBase^exp-i until exp - i = 0
  
  
}

int main (int argc, char **argv){
  // cout << numOfOnes(5) << endl; //should be 2
  // cout << numOfOnes(7) << endl; //should be 3
  // cout << numOfOnes(16) <<endl; //should be 1
  // cout << numOfOnes(15) << endl; //should be 4
  // cout << numOfOnes(121) << endl; //should be 5
  // cout << baseConverter("ABCD", 16, 10)<<endl; //should return 43981
  // cout << baseConverter("ABCD", 16, 20)<<endl; //should return 59J1
  int argv1 = std::stoi(argv[1]);
  int argv3 = std::stoi(argv[3]);
  int argv4 = std::stoi(argv[4]);
  //cout << "argv1 is " << argv1 << endl;
  //cout << "argv3 is " << argv3 << endl;
  //cout << "argv4 is " << argv4 << endl;
  cout << argv[1] << " has " << numOfOnes(argv1) << " bit(s)" << endl;
  cout << argv[2] << " (base " << argv3 << ") = " << baseConverter(argv[2], argv3, argv4) << " (base " << argv4 << ")" << endl;
}
