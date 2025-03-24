//
//  main.cpp
//  Assignment_3
//
//  Created by Maryam Elhamidi on 2025-03-21.
//

#include <iostream>
#include <queue>
using namespace std;


//will define the max size of Huffman Tree as 100
#define MAX_SIZE 100

//huffman tree node class


class HNode
{
public:
    HNode* left, * right;
    char character; //leaf nodes only
    int frequency;//internal nodes only

    //two constructors will be needed one for leaf nodes, other for internal nodes
    /* Constructor for leaf nodes */
    HNode(char c, int freq) {
        character = c;
        frequency = freq;
        left = nullptr;
        right = nullptr;
    }

    /* Constructor for internal nodes used for merging'
    two nodes together*/
    HNode(HNode* l, HNode* r) {
        character = '\0'; //no chars stored in internal node
        frequency = l->getFrequency() + r->getFrequency();
        left = l;
        right = r;

    }

    /* Function to set left node */
    void setLeft(HNode* n) {
        left = n;
    }

    /* Function to set right node */
    void setRight(HNode* n) {
        right = n;
    }

    /* Function to get left node */
    HNode* getLeft() const {
        return left;
    }

    /* Function to get right node */
    HNode* getRight() const {
        return right;
    }

    int getFrequency() const
    {
        return frequency;
    }

};


//define comparator class which will compare to look for nodes with a smaller frequency and add them to the priority queue
//first which will ensure they have a higher priority meaning they will come out first
//they need to come out first because we will be merging them to create the final Huffman Tree which has one node.


//

class CompareHNodes
{
public:
    bool operator()(HNode* first, HNode* second)
    {
        return first->getFrequency() > second->getFrequency(); //will compare frequencies of the two nodes and return true if first is 
        //bigger or has a higher frequency  than second and false otherwise. If first has a larger frequency, then it will have a lower priority
        //in the priority queue.
    }
};
// test commit
//testing push/pull for gitrepo


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
