//Anna Alberti
//aca5z
//12/1/2021
#include <string>
#include <list>
#include <iostream>
using namespace std;
#ifndef VERTEX_H
#define VERTEX_H


class Vertex{
 public:
  Vertex();

  list<string> neighbors;
  int dist;
};
#endif
