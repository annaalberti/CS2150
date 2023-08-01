//Anna Alberti 11/29/2021 aca5z
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cfloat>

using namespace std;

#include "middleearth.h"
/**
 * @include <middleearth.h.
 */


float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);
/**
// returns the distance between two cities
*/

/**
 * @brief 
 * this returns the distance between two cities
 * 
 *
 * @param  argc number of arguments
 * @param  argv array of arguments
 */
int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE

    // me.printTable();
    // cout << "---" << endl;
    // vector<string> test;
    // test.push_back("Anna");
    // test.push_back("is");
    // test.push_back("my");
    // test.push_back("name");
    // printRoute("Anna", test);

    //computeDistance(me, dests[0], dests);
    //edit dests vector
    string first = dests[0];
    float shortestDist = FLT_MAX; //set to max float value
    vector<string> shortestPath;
    if(cities_to_visit == 1) {
      shortestDist = 2*me.getDistance(dests.front(),dests.back());
      dests.erase(dests.begin());
      shortestPath = dests;
    }

    else {
    dests.erase(dests.begin()); //take off the start
    sort(dests.begin(), dests.end()); //must start on a sorted array
    
    //brute-force loop
    //cout << "before the loop" << endl;
    while(next_permutation(dests.begin(), dests.end())){ //while still more perms
      //cout << "before compute dist" << endl;
	float dist = computeDistance(me, first, dests);
	//cout << "after compute dist" << endl;
	if (dist < shortestDist){
	  //cout << "after compare " << endl;
	  shortestDist=dist; //update shortest distance
	  shortestPath=dests; //update shortestPath
	}
	//cout << "end of while" << endl;
	//cout << "dist: " << shortestDist << endl;
	//cout << "path: " << shortestPath << endl;
      }
    }
    //cout << "before print Route";
    cout << "distance: " << shortestDist << " ";
    printRoute(first, shortestPath);
    //cout << "after the loop" << endl;
    
    return 0;
}
/**
This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
*/
// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
/**
 * @brief 
 * this returns the total distance of a route from a starting place and a vector of destinations
 * 
 *
 * @return float totaldist
 * @param  me middleearth
 * @param  start beginning place
 * @param dests vector of places
 */
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
  float totaldist = 0;
  totaldist+=me.getDistance(start, dests.front());
  //cout << "start to next thing calculated " << endl;
  for (int i=0; i < dests.size()-1; i++){
    totaldist+=me.getDistance(dests[i],dests[i+1]); //get dist between two back to back cities
    //cout << "neighbors calculated" << endl;
  }
  totaldist+= me.getDistance(dests.back(),start);
  //cout << "last two things" << endl;
  return totaldist;
    
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
/**
// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
*/
/**
 * @brief 
 * this returns the total distance of a route from a starting place and a vector of destinations
 * 
 *
 * @return void
 * @param  start beginning place
 * @param dests vector of places
 */
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
  cout << start << "->";
  for(int i = 0; i < dests.size(); i++){
    cout << dests[i] << "->";
  }
  cout << start;
  
}
