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

    HNode() {};

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
        HNode* node = new HNode(left->frequency + right->frequency);

        //assigns the two nodes we got earlier from priority queue as left and right. The new node
        //is an internal node and has the frequency of left and right combined.
        node->left = left;
        node->right = right;

        //this new node needs to be pushed back into priority queue so we can continue until one node left
        pQueue.push(node);
    }

    //after while loop,  return the top on the priority queue which will be the one node left
    return pQueue.top();
}


//Harsheta Sharma 3/23/2025 10:55pm - Tried committing after creating the generateHuffmanTree but failed to commit
// Commit message: completed the generateHuffmanTree method which generates the Huffman tree using the priority queue present in the STL


//emthod to print huffman code for debugging
void printHuffmanCodes(HNode* root, int arr[], int top)
{
    
}

// --------------------------------------------------------
// Maryam's Implementation

// Recursive function to traverse the Huffman tree and generate binary codes for each character.
// These Huffman codes are stored in an array indexed by the ASCII value of each character.
void generateCodes(HNode* root, const string &code, string codes[256]) {
    if (!root) // base case, if the current node is null (empty tree or reached the end of a branch), return.
        return;
    // If this is a leaf node, save the code for the character.
    if (!root->left && !root->right) { // A leaf node is identified by having no left or right children.
        codes[(unsigned char)root->character] = code; // Store the generated binary code for this character in the 'codes' array. The array is indexed using the ASCII value of the character.
    }

    // Recursive case: Traverse the left and right subtrees
    // Append '0' when going left and '1' when going right, following the Huffman encoding rules.
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}
// Function to build a Huffman tree from a frequency table.
HNode* buildHuffmanTree(int freq[256]) {
    priority_queue<HNode*, vector<HNode*>, CompareHNodes> pq; // Create a priority queue (min-heap) to store Huffman tree nodes, which is sorted based on node frequency using compareHNodes.

    // Step 1: Create leaf nodes for all characters that have a nonzero frequency
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {  // If the character appears in the input, create a node
            pq.push(new HNode((char)i, freq[i]));  // Push a new HNode into the priority queue
        }
    }
    if (pq.empty()) // if the queue is empty, return nullptr (no Huffman tree can be built)
        return nullptr;

    // Step 2: Build the Huffman tree by repeatedly merging the two smallest nodes
    while (pq.size() > 1) {
        // Extract the two nodes with the lowest frequency
        HNode* left = pq.top();  // Smallest frequency node
        pq.pop();  // Remove it from the priority queue

        HNode* right = pq.top();  // Second smallest frequency node
        pq.pop();  // Remove it from the priority queue

        // Create a new internal node by combining these two nodes.
        // The new node's frequency is the sum of both children's frequencies.
        HNode* node = new HNode(left, right);

        pq.push(node); // Push the newly created internal node back into the priority queue to ensure that the next lowest frequency nodes will be merged in the next loop iteration.
    }
    // After the loop, only one node remains in the queue. This node is the root of the Huffman tree.
    return pq.top();
}


// --------------------------------------------------------
void decodeCodes(string codes[256], string decodedMessage) {
    HNode* i = new HNode();
    for (char c : codes){
        while(i->character == '\0') {
            if (c == 0) {
                i = i->left;
            }
            else if (c == 1) {
                i = i->right;
            }
        }
    }
    decodedMessage.append(i->character);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
