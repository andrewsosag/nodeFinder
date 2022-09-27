/*
Andrew Sosa Guaita
aguaita
andrew@sosacentral.com
WNode.h
Programming Assignment #7: Six Degrees of Bacon
*/

#ifndef W_NODE_H
#define W_NODE_H

#include <string> 
#include <vector>

class WNode{
public:
  // Singly linked list node w/ string data
  WNode(std::string s = "");
  std::string word;
  WNode* link;
};

// Typedefs
typedef WNode* WNodePtr;
typedef std::vector<WNodePtr>* WNodePtrVec;

#endif
