/*
Andrew Sosa Guaita
aguaita
andrew@sosacentral.com
baconFinder.h
Programming Assignment #7: Six Degrees of Bacon
*/

#ifndef BACON_FINDER_H
#define BACON_FINDER_H

#include "WNode.h"

class BaconFinder{
public:
  // Constructor and Destructor
  BaconFinder(std::string file);
  ~BaconFinder();

  // Data
  std::vector<std::string> dictionary; // vector of strings to store text file
  std::vector<WNodePtrVec> vectorOfVectors; // vector that stores pointer to vectors of WNodes

  // Functions
  void dictBuilder(std::string filename); // function builds string vector from text file
  WNodePtr getNodeFromDict(std::string word); // function create node and deletes word from dictionary
  WNodePtr pathFinder(std::string startingWord); // function finds path to bacon
  bool isAdjacent(std::string word1, std::string word2); // function returns if 2 words are adjacent
  void printPath(bool reverse, WNodePtr baconNode); // function prints path to bacon
};

#endif
