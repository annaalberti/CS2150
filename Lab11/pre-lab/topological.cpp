//Anna Alberti
//aca5z
//11/28/2021
//#include "node.h"
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <cstdlib>
#include <queue>
using namespace std;

//takes in one command-line parameter

/** this takes in a text file, creates a graph in the form of an unordered_map,
 * and then it will print in topological order
 *
 */
/**
 * @brief 
 *
 * this will read in a file with prereqs for each class, then it will topologically sort them
 *
 * @return return 0, but prints out the sorted order of classes
 * @param  argc is the number of arguments passed
 * @param argv is the array of arguments
 * @todo Need to write acceptance tests for this function
 */
int main(int argc, char** argv){
   // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    unordered_map<string, list<string>> adjList;
    //adjList = vector<list<string>>(100, list<string>()); //push_back vector of lists
    unordered_map<string, int> indegrees;
    
    // read in two strings
    string s1, s2;
   
    while(file >> s1 >> s2 && s1!="0" && s2!="0"){
      //check if s1 is in the unordered_map
      if(adjList.find(s1) != adjList.end()) { 
	//found
	adjList[s1].push_back(s2);
	indegrees[s2]+=1;
      } else{ //not found
	list<string> l;
	l.push_back(s2);
	adjList[s1] = l;
	indegrees[s2]+=1;
      }
      if (indegrees.find(s1) == indegrees.end()){
	indegrees[s1] = 0;
      }
    }
      
      //need to get the inital values, also insert each one into indegrees hashtable
      // if (find(adjList.begin().front(), adjList.end(), s1) != adjList.end().front()){ //if s1 is found already
	
      // } else{ //if it is not already there
      // 	list<string> l;
      // 	l.insert(s1);
      // 	adjList.push_back(l);
      // }
      // bool found = false;
      // vector<list<string>>::iterator itr;
      // for(itr == adjList.begin(); itr != adjList.end(); itr++){
      // 	if (itr->front() == s1){ if found
      // 	  itr->push_back(s2);
      // 	  indegrees[s2]+=1; if inserted, then add to the spot in the hash table
      // 	  found = true;
      // 	} if(itr == adjList.end() && found == false){
      // 	  list<string> l;
      // 	  l.push_back(s1); add s1
      // 	  l.push_back(s2); insert s2
      // 	  adjList.push_back(l);
      // 	}
      // }
      // if(itr = adjList.end()
    // for(int i =0; i < adjList.size(); i++){
    //   if (adjList[i].front() == s1){ //if already in the list
    // 	adjList[i].push_back(s2); //insert what it points to
    // 	indegrees[s2]+=1; //add to the indegrees hashtable
    //   } 
    // }

      

    // output those strings
    //cout << s1 << endl;
    //cout << s2 << endl;
    
    
    // cout << "----" << endl;
     // for(auto c:adjList){
    //    cout << "item: " << c.first;
    //    for (auto x : adjList[c.first]){
    //  	cout << "list: ";
    //  	cout  << x << endl;
    //    }
    //  }
    // // }
    // // }

    // for(auto const& y: indegrees){
    //   cout << y.first << " " << y.second << endl;
    //  }
    //topological sort - pseudocode taken from slides
    queue<string> q;
    string v;

    q.empty(); // initialize the queue

    for (auto x: indegrees){
      
      if (x.second == 0){
	q.push(x.first);
	//cout << "just pushed: " << x.first <<  endl;
      }
    }
     while (!q.empty()){
	cout <<q.front() << " ";
        v = q.front();
	q.pop();
	//for(list<string>::iterator i = adjList[v].begin(); i != adjList[v].end(); i++){ //each thing in list
	  for(auto  w: adjList[v]){
	    if (--indegrees[w] == 0){
	      //cout << "next up " << w << endl;
	    q.push(w);
	  }
         }
      
	}

    

    

    // close the file before exiting
    file.close();



    return 0;
   
}
