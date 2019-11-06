#include <iostream>
#include <string>
#include "versionControl.h"
using namespace std;

void printNodes(ostream &out, Node **headArray, int head)
{

    Node *curr = headArray[head];
    while (curr) // this for loop traverses through the nodes and calls for the object names

    {
        out << curr->data;
        if (curr->next)
        {
            out << " ";
        }
        curr = curr->next;
    }
    out << endl;
}

void attachNode(Node **headArray, int head, int index, int data)
{
    Node *curr = headArray[head];
    int bla = 0;
    for (int i = 0; i < 10; ++i) // the for loop traverses through each node, preparing
                                 // them to be nullptr, so that they can store new pointers
    {
        if (headArray[i] == nullptr)
        {
            bla = i;
            break;
        }
    }

    if (index == 0) // this takes care of the situation, where we do not branch
    {
        Node *tmp = headArray[head];
        headArray[head] = new Node{data, tmp, true};
    }
    else // and this takes care of the situation, where we change an earlier version
    {
        for (int i = 0; i < index; ++i)
        {
            curr = curr->next;
        }
        headArray[bla] = new Node{data, curr, false};
    }
}

void mutateNode(Node **headArray, int head, int index, int newValue) // runs through the list to mutate the node(file) object's property
{
    Node *curr = headArray[head];

    for (int i = 0; i < index; ++i)
    {
        curr = curr->next;
    }
    curr->data = newValue;
}

void freeLists(Node **headArray)
{
    int bla = 0;
    for (int i = 0; i < 10; ++i) // accounts for counting the heads
    {
        if (headArray[i] == nullptr)
        {
            bla = i;
            break;
        }
    }

    Node *hmm = headArray[0];
    while (hmm)
    {
        Node *tmp = hmm;
        hmm = hmm->next;
        delete tmp;
    }

    int i = 1;
    while (i < bla) // accounts for getting rid of the pointers in the heap, preventing memory loss
    {
        Node *curr = headArray[i];
        while (!false)
        {
            if (curr->ownsSuccessor == false)
            {
                delete curr;
                break;
            }
            else
            {

                Node *tmp = hmm;
                curr = curr->next;
                delete tmp;
            }
            i += 1;
        }
        i += 1;
    }
}