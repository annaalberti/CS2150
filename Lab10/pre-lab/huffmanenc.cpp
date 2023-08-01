//Anna Alberti
//aca5z 11/18/2021
#include "heap.h"
#include "HuffNode.h"
#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

unordered_map<char, string> prefixes;
//string bits = "";

void traverse(HuffNode* node, string bits){
  //as long as not a leaf node (children aren't null)
  //base case for leaf nodes, "/0" bc dont wanna add intermediate nodes
  if (node->right == NULL && node->left == NULL && node->character >= 0x20 && node->character <= 0x7e){
    
  prefixes[node->character] = bits; //add to hash table
  // if(node->character == ' '){ //need to print 'space' not ' '
  //   cout << "space " <<  bits<< endl;
  //   }
  // if (node->character != ' '){ // for everything other than ' '
  // cout << node->character << " " << bits << endl;
  // string ret = (char)node->character + " " + bits;
  // return ret;
  // }
  //bits=bits.substr(0, bits.size()-1); //take off last thing add to be able to go to the other side
  }

  //return traverse(node->left, bits+"0") + traverse(node->right, bits+"1");
  if(node->left != NULL){
    //bits+="0";
    traverse(node->left, bits+"0");
  }
  if(node->right !=NULL){
    //bits+="1";
    traverse(node->right, bits+"1");
  }
  
}

int main(int argc, char** argv){
  
  //STEP 1: READING IN THE FILE AND COUNT HOW OFTEN EACH CHAR APPEARS. STORE IN A HASHTABLE
  //need to intialize the hashtable for storing the chars and frequencies
  unordered_map<char, int> hashTable;
  //set everything in hashTable = 0; ?????????????
  
  // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // read in characters one by one, until reading fails (we hit the end of the file)
    char g;
    while (file.get(g)) {
      if( g >= 0x20 && g <= 0x7e){ //if it's not a new line character and it's printable

	// if(g == 0x20){ //if it's a space
	//   hashTable["space"]=+1; //told to replace ' ' with 'space' in pre-lab instructions
	// }
	//if not in it, set to 1
	// if(hashTable.find(g) == hashTable.end()){ 
	//   hashTable[g] = 1;
	// }
	//if it's already in it,
      hashTable[g]+=1; //increment frequency by one for each time it is found in the file
      //cout <<" freq " << g << ": " << hashTable[g] << endl;
      }
    }

    // once we hit the end of the file we are marked as "failed", so clear that
    // then "seek" to the beginning of the file to start again
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);

    file.close();


    //STEP 2: create a min heap that stores pointers to HuffNodes with priority being low frequency
    heap minHeap;
    for(auto const& x: hashTable){ //need to know how to iterate through a hashtable????
      HuffNode* newNode = new HuffNode();
      //cout << x.first << ": " <<  x.second << endl;
  
      newNode->character = x.first;
      newNode->freq = x.second;
      minHeap.insert(newNode);
    }
    // cout << "test:---------------------------" << endl;
    // minHeap.print();
    // cout << minHeap.findMin()->character << ": " << minHeap.deleteMin()->freq <<endl;
    //     cout << minHeap.findMin()->character << ": " << minHeap.deleteMin()->freq <<endl;
    // cout << minHeap.findMin()->character << ": " << minHeap.deleteMin()->freq <<endl;
    // cout << minHeap.findMin()->character << ": " << minHeap.deleteMin()->freq <<endl;
    // cout << minHeap.findMin()->character << ": " << minHeap.deleteMin()->freq <<endl;
    // cout << minHeap.findMin()->character << ": " << minHeap.deleteMin()->freq <<endl;
    // cout << minHeap.findMin()->character << ": " << minHeap.deleteMin()->freq <<endl;
    // cout << minHeap.findMin()->character << ": " << minHeap.deleteMin()->freq <<endl;
    // cout << minHeap.findMin()->character << ": " << minHeap.deleteMin()->freq <<endl;
    // cout << minHeap.findMin()->character << ": " << minHeap.deleteMin()->freq <<endl;
    // cout << minHeap.findMin()->character << ": " << minHeap.deleteMin()->freq <<endl;
    // cout << minHeap.findMin()->character << ": " << minHeap.deleteMin()->freq <<endl;

        



    
    //STEP 3: build the Huffman tree
    while(minHeap.heap_size > 1){
      //while heap_size > 1
      //cout << "new temp node " << endl;
    HuffNode* interNode = new HuffNode(); //intermediate node
    //cout <<"left child: " << minHeap.findMin()->character << minHeap.findMin()->freq<< endl;
    int left = minHeap.findMin()->freq;
    interNode->left = minHeap.findMin(); //first value = left child
    minHeap.deleteMin();
    //cout <<"right child: " <<  minHeap.findMin()->character << minHeap.findMin()->freq<< endl;
    int right = minHeap.findMin()->freq;
    interNode->right = minHeap.findMin(); //second value = right child
    minHeap.deleteMin();
    interNode->freq = left+right; //calculate new frequency
    //interNode->character = NULL;  //it has no value for char
    minHeap.insert(interNode); // put back onto the vector
      }
    //cout << "---------------------------" << endl;
    //minHeap.print();
    
    //cout << "SECTION1:" << endl;
    //STEP 4: Traverse the tree to get the bit strings
    traverse(minHeap.findMin(), ""); //traverse starting with the root of the tree
    //this  prints them out too
    for(auto const& x: prefixes){
      if(x.first == ' '){
	cout << "space " << x.second << endl;
      }
      if(x.first != ' '){
      cout << x.first << " " << x.second << endl;
      }
    }
    int count2 = 0;
    float cost = 0;
    for(auto const& x: hashTable){
      //cout << x.first << ": " << x.second << endl;
     count2+= x.second;
     //cost calculation
	  //frequency / total * length of prefix ? --> unique
	  cost += (float)(hashTable[x.first]*prefixes[x.first].length());
    }
        cost= cost/(float)(count2);

    
    cout << "----------------------------------------" << endl;

    //STEP 5: re-read file and print out prefixes
    ifstream file1(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file1.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // read in characters one by one, until reading fails (we hit the end of the file)
    char a;
    //vector<char> letters;
    int count=0;
    string total_string = "";
    while (file1.get(a)) {
      //if(find(letters.begin(), letters.end(), a)!=letters.end()){ //this is so it only prints each once
      //letters.push_back(a);
      total_string +=prefixes[a];
	  cout << prefixes[a] << " ";
	  count+=1;
      //}
	  
    }
    cout << endl;

        cout << "----------------------------------------" << endl;

	
// once we hit the end of the file we are marked as "failed", so clear that
    // then "seek" to the beginning of the file to start again
    file1.clear(); // Clears the _state_ of the file, not its contents!
    file1.seekg(0);

    file1.close();

    //loop through hashTable, count enteries greater than 0 x.second for frequency

    float compRatio = (float)((count2)*8)/total_string.length();
    float costPrint = (float)cost;

    cout << "There are a total of " << count2 << " symbols that are encoded." << endl;
    cout << "There are " << hashTable.size() << " distinct symbols used." << endl;
    cout << "There were " << (count2)*8 << " bits in the originial file." << endl;
    cout << "There were " << total_string.length() << " bits in the compressed file." << endl;
    cout <<fixed<<setprecision(5)<<"This gives a compression ratio of " << compRatio << "." << endl;
    cout<<fixed<<setprecision(5)<< "The cost of the Huffman tree is " << costPrint << " bits per character." << endl;
    

    //QUESTIONS
    //why count - 1?
    //why prefixes.size()-1?
    //is it okay that my things r diff
    //normaltxt2 - order matter at top?
     //where to implement space thing??
     //destructor?
     //float to 5 decimal places
     //cost error
  return 0;
}
