//
//  huffman_tree.cpp
//  Assignment_3
//
//  Created by Maryam Elhamidi on 2025-03-21.
//Huffman Tree Node class\\

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

    int getFrequency()
    {
        return frequency;
    }

};

