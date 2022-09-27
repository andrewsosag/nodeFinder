/*
Andrew Sosa Guaita
aguaita
andrew@sosacentral.com
baconFinder.cpp
Programming Assignment #7: Six Degrees of Bacon
*/

#include <iostream>
#include <fstream>
#include "baconFinder.h"

using namespace std;

// Constructor
BaconFinder::BaconFinder(string file){
  // Construct dictionary from file path
  dictBuilder(file);
};

// Destructor
BaconFinder::~BaconFinder(){
  WNodePtrVec innerVector;
  WNodePtr node;
  // Loop through each vector of vectors
  for(int i = 0; i < vectorOfVectors.size(); i++){
    innerVector = vectorOfVectors[i];
    // Delete all nodes in each vector
    for(int j = 0; j < innerVector->size(); j++){
      node = innerVector->at(j);
      delete node;
    }
    // Delete each vector
    delete innerVector;
  }
};

// Function fills dictionary vector with text file
// Input: filename as a string
// Output: Fills dictionary vector with each word in file
void BaconFinder::dictBuilder(string filename){
  string currentWord; 
  ifstream inputStream(filename.c_str());

  // read file stream and insert into dictionary vector
  while(getline(inputStream, currentWord)){
    dictionary.push_back(currentWord);
  }
  inputStream.close();;
};

// Function finds word in dictionary and returns WNode
// Input: word as a string
// Output: removes word from dictionary and returns WNode,
//         returns NULL if word is not found in dictonary
WNodePtr BaconFinder::getNodeFromDict(string word){
  WNodePtr node = new WNode(word);
  // Loop through dictionary and find word
  for(int i = 0; i < dictionary.size(); i++){
    // If word is found, remove from dictionary and return WNode
    if (dictionary[i] == word){
      dictionary.erase(dictionary.begin()+i);
      return node;
    }
  }
  // Return NULL if word is not found in dictionary
  return NULL;
}


// Function finds path to bacon from starting word
WNodePtr BaconFinder::pathFinder(string startingWord){
  // Create node for starting word
  WNodePtr node = getNodeFromDict(startingWord);

  // return NULL if starting word is not found in dictionary
  if (node == NULL) { 
    return NULL;
  }

  // Create starting vector insert add starting node
  WNodePtrVec startingVec = new vector<WNodePtr>;
  startingVec->push_back(node);

  // Insert starting vector into the vector of vectors
  vectorOfVectors.push_back(startingVec);
  WNodePtrVec adjacencyVec;

  // Find path to bacon
  bool baconFound = false;
  while(!baconFound){
    // Create adjacenct vector and insert into vector of vectors
    adjacencyVec = new vector<WNodePtr>;
    vectorOfVectors.push_back(adjacencyVec);

    // Find vector sizes to prevent going out of bounds
    WNodePtrVec previousVector = vectorOfVectors[vectorOfVectors.size()-2];
    WNodePtrVec currentVector = vectorOfVectors[vectorOfVectors.size()-1];

    // Loop through previous vector
    for (int i = 0; i < previousVector->size(); i++){
      WNodePtr searchWord = previousVector->at(i);
      // Loop through the dictionary
      for (int j = 0; j < dictionary.size(); j++){
        // If word is adjacent, create node and insert in adjacent vector
        if(isAdjacent(searchWord->word, dictionary[j])){
          WNodePtr adjacentWord = new WNode(dictionary[j]);
          currentVector->push_back(adjacentWord);
          // Delete word from the dictionary
          dictionary.erase(dictionary.begin()+j);   
          // Create a link for adjacent word
          adjacentWord->link = searchWord;
          // If adjacent word is bacon, return node
          if (adjacentWord->word == "bacon"){
            baconFound = true;
            return adjacentWord;
          }
        }
      }
    }
    // If no adjacent words are found, exit
    if (adjacencyVec->size() == 0){
      baconFound = true;
    }
  }
  return NULL; // Return null if no path to "bacon" was found.
};

// Function returns true if 2 words are adjacent, else returns false
bool BaconFinder::isAdjacent(string word1, string word2){
  int adjacentLetters = 0;
  // Loop through both words and find count of adjacent letters
  for (int i = 0; i < 5; i++) {
    if (word1[i] == word2[i]){
      adjacentLetters++;
    }
  }
  // Return true if 4 letters are adjacent
  return(adjacentLetters == 4);
};

// Function prints path to bacon from starting word
void BaconFinder::printPath(bool reverse, WNodePtr baconNode){
  vector<string> wordPath;
  
  // Use vector of strings to store linked WNodes
  bool end = false;
  while(!end){
    if (baconNode->link == NULL){
      end = true;
    }
    wordPath.push_back(baconNode->word);
    baconNode = baconNode->link;
  }

  // If reverse is true, output the vector backwards
  if(reverse){
    for(int i = wordPath.size()-1; i >= 0; i--){
      cout << wordPath[i] << endl;
    }
  } else {
  // If reverse is false, output the vector normally
    for(int i = 0; i < wordPath.size(); i++){
      cout << wordPath[i] << endl;
    }
  }
};
