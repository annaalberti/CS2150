// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <unordered_map>
#include <string>
using namespace std;


// main(): we want to use parameters
int main (int argc, char** argv) {
  //creating same data structures
  
  unordered_map<string, string> prefixes;

  
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code

	prefixes[prefix] = character; //add prefix for each char to hash tabl
	
    }
    // for(auto const& x: prefixes){
    //   cout << x.first << ": " << x.second << endl;
    // }
    //cout << prefixes["0"] << endl;
    // string word;
    // while(file >> word){
    //   cout << prefixes[word] << endl;
    // }

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
	//cout << bits << endl;
        file >> bits;
      //cout << prefixes[bits];
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }
  //cout << endl;

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();


    string str = "";
    string ret = "";
    for(int i= 0; i <= allbits.size(); i++){
      if(prefixes.find(str)!= prefixes.end()){

	  ret+=prefixes[str];
	  str = "";
	}
    
	str+=allbits[i];
	//cout << str;
      
      
    }

    cout << ret << endl;

    //-------------

    // verify the correct number of parameters
    // if (argc != 2) {
    //     cout << "Must supply the input file name as the one and only parameter" << endl;
    //     exit(1);
    // }

    // // attempt to open the supplied file
    // // ifstream stands for "input file stream"
    // ifstream file1(argv[1]);
    // // if the file wasn't found, output an error message and exit
    // if (!file1.is_open()) {
    //     cout << "Unable to open '" << argv[1] << "' for reading" << endl;
    //     exit(2);
    // }

    // // read in characters one by one, until reading fails (we hit the end of the file)
    // string word;
    // while (file1 >> word) {
    //   cout << prefixes[word];
    // }

    // file1.clear(); // Clears the _state_ of the file, not its contents!
    // file1.seekg(0);

    // file1.close();

    return 0;
}
