//Anna Alberti
//aca5z
//11/30/2021

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <unordered_map>
#include <queue>


/**
 * @include iostream
 */
using namespace std;

//questions
//1. hard coding to get neighbors
//2. storing the "graph" --> use unordered_map<int[3][3], list<int[3][3]>> ?
//3. pseudocode for unweighted shortest path in slides, how will that translate to this?

/** @brief will return all the possible configurations from the given grid
 */
//this function will get the neighboring configurations give the placement
// of the 0 in the array
//it returns the given puzzle, but with pointers to it's neighbors
list<string> getNeighbors(string puzz){
  string grid1 = puzz;
  string grid2 = puzz;
  string grid3 = puzz;
  string grid4 = puzz;
  list<string> allNeighbors;
  if(puzz[0] == '0'){ //top left corner
    grid1[0] = puzz[1];
    grid1[1] = '0';
    allNeighbors.push_back(grid1);
    grid2[0] = puzz[3];
    grid2[3] = '0';
    allNeighbors.push_back(grid2);
    
  }if(puzz[1] == '0'){ //top middle
    grid1[1] = puzz[0];
    grid1[0] = '0';
    allNeighbors.push_back(grid1);
    grid2[1] = puzz[2];
    grid2[2] = '0';
    allNeighbors.push_back(grid2);
    grid3[1] = puzz[4];
    grid3[4] = '0';
    allNeighbors.push_back(grid3);
    
  }if(puzz[2] == '0'){ // top right corner
    grid1[2] = puzz[1];
    grid1[1] = '0';
    allNeighbors.push_back(grid1);
    grid2[2] = puzz[5];
    grid2[5] = '0';
    allNeighbors.push_back(grid2);
    
  }if(puzz[3] == '0'){ //left middle
    grid1[3] = puzz[0];
    grid1[0] = '0';
    allNeighbors.push_back(grid1);

    grid2[3] = puzz[6];
    grid2[6] = '0';
    allNeighbors.push_back(grid2);

    grid3[3] = puzz[4];
    grid3[4] = '0';
    allNeighbors.push_back(grid3);
  }if(puzz[4] == '0'){ //center
    grid1[4] = puzz[1];
    grid1[1] = '0';
    allNeighbors.push_back(grid1);

    grid2[4] = puzz[5];
    grid2[5] = '0';
    allNeighbors.push_back(grid2);

    grid3[4] = puzz[7];
    grid3[7] = '0';
    allNeighbors.push_back(grid3);

    grid4[4] = puzz[3];
    grid4[3] = '0';
    allNeighbors.push_back(grid4);
    
  }if(puzz[5] == '0'){ // right middle
    grid1[5] = puzz[2];
    grid1[2] = '0';
    allNeighbors.push_back(grid1);

    grid2[5] = puzz[8];
    grid2[8] = '0';
    allNeighbors.push_back(grid2);

    grid3[5] = puzz[4];
    grid3[4] = '0';
    allNeighbors.push_back(grid3);

  }if(puzz[6] == '0'){ //bottom left corner
    grid1[6] = puzz[3];
    grid1[3] = '0';
    allNeighbors.push_back(grid1);

    grid2[6] = puzz[7];
    grid2[7] = '0';
    allNeighbors.push_back(grid2);
    
  }if(puzz[7] == '0'){ //bottom middle
    grid1[7] = puzz[6];
    grid1[6] = '0';
    allNeighbors.push_back(grid1);

    grid2[7] = puzz[8];
    grid2[8] = '0';
    allNeighbors.push_back(grid2);

    grid3[7] = puzz[4];
    grid3[4] = '0';
    allNeighbors.push_back(grid3);
    
  }if(puzz[8] == '0'){ //bottom right corner
    grid1[8] = puzz[5];
    grid1[5] = '0';
    allNeighbors.push_back(grid1);

    grid2[8] = puzz[7];
    grid2[7] = '0';
    allNeighbors.push_back(grid2);
  }

  return allNeighbors;
}
//this function will create an adjacency list to represent the graph,
//stopping when the neighbor generated is the goal
/** @brief main method. this is where my breadth first search occurs
 */
int main(){
  string goal = "123456780";
  string puzz = "";
  cout << "Enter puzzle " <<endl;
  string input;
  char a, b, c;
  while(getline(cin,input)  && !input.empty() && puzz.length() <8){
    
    stringstream ss(input);
    ss >> a >> b >> c;
    if (!ss) {
      cout << "invalid" << endl;
    } else{
      puzz+= a;
      puzz+=b;
      puzz+=c;
    }
  }

  
  //unordered_map<string, list<string>> graph;
  unordered_map<string, int> visited;
  
  cout << "Solving puzzle" << endl;
  queue<string> q;
  string v;
  //int moves = 0;
  q.push(puzz);
  visited[puzz] = 0;
  while(!q.empty()){
    v = q.front(); //check here
    q.pop();

    for( auto w: getNeighbors(v)){
      if( w == goal){
	//cout << "Goal reached!" << endl;
	cout << visited[v]+1;
	return 0;
      }
      else if(visited.find(w) == visited.end()){ //see isn't in hash map
	q.push(w);
	visited[w] = visited[v]+1;
	//moves++;
      }
    }
    
  }
  cout << "IMPOSSIBLE" << endl;
  //impossible here
  return 0;
    
  
  //test to see if my string is what i want it to be
  //cout << puzz << endl;

  // list<string> l = getNeighbors(puzz);
  // cout << "the other puzz" << endl;
  // for(auto x: l){
  //   cout << "one combo: " << endl;
  //   cout << x << endl;
  // }
//    return 0;

}

