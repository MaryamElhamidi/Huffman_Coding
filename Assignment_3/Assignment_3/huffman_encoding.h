//
//  huffman_encoding.h
//  Assignment_3
//
//  Created by Maryam Elhamidi on 2025-03-21.
//
#ifndef HUFFMAN_ENCODING_H
#define HUFFMAN_ENCODING_H

#include "huffman_tree.cpp"
#include <string>

using namespace std;

// Function to generate Huffman codes from the Huffman tree
void generateCodes(HNode* root, const string &code, string codes[256]);

// Function to build a Huffman tree from a character frequency table
HNode* buildHuffmanTree(int freq[256]);

string decodeCodes(const string& code, HNode* root) {};

#endif
