# 6 Degrees of Bacon using C++ Linked Lists
The "6 Degrees of Kevin Bacon" is an internet joke suggesting that any actor is within six degrees of seperation from Kevin Bacon.

This program uses C++ linked lists to find a path of adjacent words to the word "bacon". An adjacent word is any word that shares 4/5 of the same characters as the next word.

## Setup
1. Download all files except for README.md
2. Compile using "make"
```bash
make
```
3. Run using "./p7 filename"
```bash
./p7 sgb-words.txt
```
(To print the path to "bacon" in reverse)
```bash
./p7 sgb-words.txt -r
```

## Usage
1. After running the program, type a five letter word into the prompt (only words within the text file will work)
2. The program will search for the word "bacon"
3. If a path to "bacon" is found, the program will print the path to "bacon"
4. If a path to "bacon is not found, the program will exit and print "no path to bacon"

## How it Works
1. The program uses a singly linked list in order to store words and find the path to "bacon"
```c++
// Singly linked list node containing word and link
class WNode{
    WNode(string s = "");
    string word;
    WNode* link;
};
```
2. Using vectors of pointers to other vectors, the program is able to dynamically construct a path to the word bacon
```c++
vector<WNodePtrVec> vectorOfVectors; // vector that stores pointer to vectors of WNodes
  
// Create adjacenct vector and insert into vector of vectors
adjacencyVec = new vector<WNodePtr>;
vectorOfVectors.push_back(adjacencyVec);
```
3. The program loops through the dictionary and dynamically creates a vector if an adjacent word is found
```c++
// Loop through the dictionary
    for (int j = 0; j < dictionary.size(); j++){
    // If word is adjacent, create node and insert in adjacent vector
    if(isAdjacent(searchWord->word, dictionary[j])){
        WNodePtr adjacentWord = new WNode(dictionary[j]);
        currentVector->push_back(adjacentWord);
```
4. The adjacent word is removed from the dictionary, and a link to the adjacent word is created
```c++
// Delete word from the dictionary
dictionary.erase(dictionary.begin()+j);   
// Create a link for adjacent word
adjacentWord->link = searchWord;
```
5. The program continues to loop through the dictionary until:
    - Bacon is the adjacent word, and the program iterates through the linked list printing the path to "bacon"
    - Bacon is never found, and the program exits
