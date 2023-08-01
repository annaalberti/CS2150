//Anna Alberti aca5z
// 10/13/2021

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class hashTable {
public:
  hashTable(int num); // constructor
  //~hashTable(); //destructor

  int getNextPrime(unsigned int n);
  bool checkprime(unsigned int n);
  unsigned int hashFunction(string value);
  bool find(string value);
  void insert(string value);
  //void rehash();
private:
  vector<list<string>> table;
};

#endif
