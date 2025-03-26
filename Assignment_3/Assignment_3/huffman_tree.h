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

class HNode {

	HNode() {};

	HNode(char c, int freq) {};

	HNode(HNode* l, HNode* r) {};
	void setLeft(HNode* n) {};

	void setRight(HNode* n) {};

	HNode* getLeft() const {};

	HNode* getRight() const {};
};


class CompareHNodes
{
	bool operator()(HNode* first, HNode* second) {};
};

HNode* generateHuffmanTree(priority_queue<HNode*, vector<HNode*>, CompareHNodes> pQueue) {};


#endif // !HUFFMAN_TREE

