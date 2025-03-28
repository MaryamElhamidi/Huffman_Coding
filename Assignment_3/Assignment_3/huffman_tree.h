//
//  huffman_tree.h
//  Assignment_3
//
//  Created by Maryam Elhamidi on 2025-03-21.
//


#ifndef HUFFMAN_TREE
#define HUFFMAN_TREE

#include <iostream>
using namespace std;

class HNode {//edit- maryam edited this to ensure classes and functions are declared properly & no errors.
    public:
    char character; // Character of the node (valid only for leaf nodes)
    int frequency; // Frequency of the character or sum of frequencies for internal nodes
    HNode* left; // Left child
    HNode* right; // Right child

    HNode(char c, int freq); // Constructor for leaf nodes
    HNode(HNode* l, HNode* r); // Constructor for internal nodes used for merging two nodes together

    // Default constructor
    HNode() : character('\0'), frequency(0), left(nullptr), right(nullptr) {}
    
        void setLeft(HNode* n);
        void setRight(HNode* n);
        HNode* getLeft() const;
        HNode* getRight() const;
};


class CompareHNodes {
public:
    bool operator()(const HNode* first, const HNode* second) const;
};

HNode* generateHuffmanTree(std::priority_queue<HNode*, std::vector<HNode*>, CompareHNodes>& pQueue);

#endif // !HUFFMAN_TREE

