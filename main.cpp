/*
Andrew Sosa Guaita
aguaita
andrew@sosacentral.com
main.cpp
Programming Assignment #7: Six Degrees of Bacon
*/
/*
Program uses pointers to words stored in "WNodes" to
find the path to "bacon". Using the -r flag allows 
you to output the path to bacon in reverse.
Working / Tested
*/
#include <iostream>
#include "baconFinder.h"


using namespace std;

int main(int argc, char** argv) {
  cout << "Andrew Sosa Guaita, andrew@sosacentral.com" << endl;

  bool reverse;
  string filename;

  // Parse command line arguments for file path and reverse flag
  if (argc < 2) {
    cout << "you need to enter at least a filename." << endl;
    return 0;
  }
  if (argc == 3){
    string argv1 = argv[1];
    if (argv1 == "-r"){
      reverse = true;
      filename = argv[2];
    } else {
      reverse = true;
      filename = argv[1];
    }
  } else {
    filename = argv[1];
    reverse = false;
  }

  // Store word from user in key
  string key;
  cout << "Your word?";
  getline(cin, key);

  // If input is bacon, end program
  if (key == "bacon") {
    cout << "bacon" << endl;
    return 0;
  }
  
  // Find Path to Bacon
  BaconFinder pathToBacon(filename);
  WNodePtr startOfPath = pathToBacon.pathFinder(key);

  // Print path to bacon
  if(startOfPath == NULL){
    cout << "no path from " << key << " to bacon." << endl;
  } else {
    pathToBacon.printPath(reverse, startOfPath);
  }
}

