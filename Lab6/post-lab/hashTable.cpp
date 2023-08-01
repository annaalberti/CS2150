//Anna Alberti aca5z
//10/13/2021

#include "hashTable.h"
//#include "primenumber.cpp"
#include <list>
#include <vector>
#include <tgmath.h> 

using namespace std;

bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}


hashTable::hashTable(int num){
  num *= 2; //for load factor of .5
  if (checkprime(num)){
    table= vector<list<string>>(num,list<string>());  //pushback empty lists

  } else {
    getNextPrime(num);
    table= vector<list<string>>(num,list<string>()); //pushback empty lists
  }
}

//hashTable::~hashTable(){
  // for (int i = 0; i <= table.size(); i++){
  //   delete table[i];
  // }
//}

unsigned int hashTable::hashFunction(string value){
  //from slides:
  //for each letter in the string, add to x = 0 , key[i] * pow (37,i)
  //then mod by the table size

  unsigned int x = 0;
  // for (int i =0; i < value.length()-1; i++){
  //   x+= value[i] *pow(37,i);
  // }
  for (int i= 0; i< value.length()-1; i++){
    //x += value[i] *3 +5;
    x+= value[i];
    x*=31;
}
  return x % table.size();
  
  
}


bool hashTable::find(string value){
  //call List's find on each index of the array
  int x = hashFunction(value);
  for (list<string>::iterator itr = table[x].begin(); itr!=  table[x].end(); itr++){
      if( *itr == value){ //how to access the string in the list?
	return true;
      } 
  }
  //else {
  //   return false;
  // }
  return false;
  }


void hashTable::insert(string value){
  int x = hashFunction(value);
  table[x].push_back(value);
}

//void hashTable::rehash(){ //make new hash table double the size and copy all the values over
// }
