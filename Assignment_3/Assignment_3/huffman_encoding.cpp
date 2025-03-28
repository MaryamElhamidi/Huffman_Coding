//
//  huffman_encoding.cpp
//  Assignment_3
//
//  Created by Maryam Elhamidi on 2025-03-21.
//

#include "huffman_encoding.h"
#include "huffman_tree.h"
#include <queue>
#include <iostream>

using namespace std;

// --------------------------------------------------------
// Maryam's Implementation

// Recursive function to traverse the Huffman tree and generate binary codes for each character.
// These Huffman codes are stored in an array indexed by the ASCII value of each character.
void generateCodes(HNode* root, const string &code, string codes[256]) {
    if (root ==  nullptr){ // base case, if the current node is null (empty tree or reached the end of a branch), return.
        return;
        // If this is a leaf node, save the code for the character.
    }
    if (!root->getLeft() && !root->getRight()) { // A leaf node is identified by having no left or right children.
    codes[(unsigned char)root->character] = code; // Store the generated binary code for this character in the 'codes' array. The array is indexed using the ASCII value of the character.
    } else {     // Recursive case: Traverse the left and right subtrees
        // Append '0' when going left and '1' when going right, following the Huffman encoding rules.
        generateCodes(root->getLeft(), code + "0", codes);
        generateCodes(root->getRight(), code + "1", codes);
    }
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
//    if (pq.empty()) // if the queue is empty, return nullptr (no Huffman tree can be built)
//        return nullptr;
//
//    // Step 2: Build the Huffman tree by repeatedly merging the two smallest nodes
//    while (pq.size() > 1) {
//        // Extract the two nodes with the lowest frequency
//        HNode* left = pq.top();  // Smallest frequency node
//        pq.pop();  // Remove it from the priority queue
//
//        HNode* right = pq.top();  // Second smallest frequency node
//        pq.pop();  // Remove it from the priority queue
//
//        // Create a new internal node by combining these two nodes.
//        // The new node's frequency is the sum of both children's frequencies.
//        HNode* node = new HNode(left, right);
//
//        pq.push(node); // Push the newly created internal node back into the priority queue to ensure that the next lowest frequency nodes will be merged in the next loop iteration.
//    }
//    // After the loop, only one node remains in the queue. This node is the root of the Huffman tree.
//    return pq.top();
    generateHuffmanTree(pq);
    return pq.top();
}
// --------------------------------------------------------
// -------------------------------------------------------- Janki implementation
string decodeCodes(const string& code, HNode* root) {

    string decodeMessage = "";
    HNode* iteratorNode = root;

    for (char bit : code) {
        
        if (bit == '0')
        {
            iteratorNode= iteratorNode->getLeft();
        }
        else
        {
            iteratorNode = iteratorNode->getRight();
        }
        // Check if the current node is a leaf node
        if (!iteratorNode->getLeft() && !iteratorNode->getRight())
        {
            decodeMessage += iteratorNode->character;
            iteratorNode = root;
        }
    }
    return decodeMessage;
}

