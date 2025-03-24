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


//can remove getFrequency() because is a publically accessed
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
        frequency = l->frequency + r->frequency;
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

};


//define comparator class which will compare to look for nodes with a smaller frequency and add them to the priority queue
//first which will ensure they have a higher priority meaning they will come out first
//they need to come out first because we will be merging them to create the final Huffman Tree which has one node.

class CompareHNodes
{
public:
    bool operator()(HNode* first, HNode* second)
    {
        return first->frequency > second->frequency; //will compare frequencies of the two nodes and return true if first is 
        //bigger or has a higher frequency  than second and false otherwise. If first has a larger frequency, then it will have a lower priority
        //in the priority queue.
    }
};


//create function which will generate Huffman tree according to algorithm 

HNode* generateHuffmanTree(priority_queue<HNode*, vector<HNode*>,CompareHNodes> pQueue) //using Priority queue present in STL, we are able to use
//the CompareHNodes defined above to ensure our queue is sorted properly. The nodes with the smallest frequencies will at at the top of the queue
{
    //keep looping until one node lefts in priority queue due to structure of Huffman Tree
    while(pQueue.size()!=1)
    {

        //node with least frequency from priority queue is stored in left

        HNode* left = pQueue.top();
        pQueue.pop(); //then this leat frequency will be popped so we can access next element
        
        //node with the next least frequency is stored in right
        HNode* right = pQueue.top();
        pQueue.pop(); //pop this node from priority queue.

        //a new node must be made which stores the frequency of left and right combined
        HNode* node= new HNode(left->frequency + right->frequency)





    }
}
// test commit
//testing push/pull for gitrepo


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
