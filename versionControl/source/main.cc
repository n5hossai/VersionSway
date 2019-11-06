#include <iostream>
#include <string>
#include "versionControl.h"
using namespace std;

int main()
{
  string command;
  int head;

  Node *n1 = new Node{0, nullptr};
  Node *n2 = new Node{7, n1};
  Node *n3 = new Node{6, n2};
  Node *n4 = new Node{5, n3};
  Node *n5 = new Node{4, n4};
  Node *n6 = new Node{3, n5};
  Node *n7 = new Node{2, n6};
  Node *n13 = new Node{1, n7};
  Node *n8 = new Node{11, n3};
  Node *n9 = new Node{12, n8};
  Node *n10 = new Node{13, n9};
  Node *n11 = new Node{10, n7};
  Node *n12 = new Node{14, n9};

  Node *n15 = new Node{17, nullptr};

  Node *heads[numHeads] = {n1, nullptr};

  while (cin >> command)
  {
    if (command == "print")
    {
      cin >> head;
      printNodes(cout, heads, head); // prints nodes
    }

    else if (command == "attach")
    {
      int m, x;
      cin >> head >> m >> x;
      attachNode(heads, head, m, x); // attaches nodes
    }

    else if (command == "mutate")
    {
      int m, x;
      cin >> head >> m >> x;
      mutateNode(heads, head, m, x); // mutates nodes
    }

    //
  }

  freeLists(heads); // frees the nodes in the heap array
}
