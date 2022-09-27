/*
Andrew Sosa Guaita
aguaita
andrew@sosacentral.com
WNode.cpp
Programming Assignment #7: Six Degrees of Bacon
*/

#include "WNode.h"

using namespace std;

// Constructor builds WNode
WNode::WNode(string s){
  word = s;
  link = NULL; 
};