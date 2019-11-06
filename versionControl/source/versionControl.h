#ifndef NODE_H
#define NODE_H
#include <ostream>

struct Node
{
  int data;
  Node *next;
  bool ownsSuccessor; //keeps track if it is a true descendant, or just a branch
};

const int numHeads = 10;

// Implement these four functions
void printNodes(std::ostream &out, Node **headArray, int head);
void attachNode(Node **headArray, int head, int index, int data);
void mutateNode(Node **headArray, int head, int index, int newValue);

void freeLists(Node **headArray);

#endif
