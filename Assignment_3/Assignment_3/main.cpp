//
//  main.cpp
//  Assignment_3
//
//  Created by Maryam Elhamidi on 2025-03-21.
//
#include <iostream>
#include <string>
#include <map>
#include "file_handling.h"
#include "huffman_tree.h"
#include "huffman_encoding.h"

using namespace std;

// Function to print Huffman codes cleanly using simple tabs for alignment
void printHuffmanCodes(const string codes[256]) {
    cout << "Huffman Codes:\n";
    cout << "Character" << "\t" << "Code\n";
    for (int i = 0; i < 256; ++i) {
        if (!codes[i].empty()) {
            cout << char(i) << "\t\t" << codes[i] << "\n";
        }
    }
}

int main() {
    string fileName = "/Users/Yammy/Documents/huffman_test.txt"; // Hardcoded path

    // if one of you guys want to try to make is dynamic here's an approach i tried, if you wanna build on it.
//    string fileName;
//    cout << "Please enter the full path of the file to encode: ";
//    getline(cin, fileName);  // Use getline to allow spaces in file path if necessary

    string text = readFile(fileName);
    if (text.empty()) {
        cerr << "Failed to read file or file is empty." << endl;
        return 1;
    }

    // Calculate frequency of each character
    map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }

    // Create a priority queue and populate it with nodes created from the frequency map
    priority_queue<HNode*, vector<HNode*>, CompareHNodes> pq;
    for (auto& p : freq) {
        pq.push(new HNode(p.first, p.second));
    }

    // Generate Huffman Tree
    HNode* root = generateHuffmanTree(pq);

    // Generate Huffman Codes
    string codes[256]; // Array to store Huffman codes
    generateCodes(root, "", codes);

    // Print the Huffman codes
    printHuffmanCodes(codes);

    //Encode the text using the Huffman codes
    string encodedText;
    for (char c : text) {
        encodedText += codes[(unsigned char)c];
    }

    // Display encoded text to user
    cout << "Encoded Text: " << encodedText << endl;

    // Decode the text (demonstration)
    string decodedText = decodeCodes(encodedText, root);
    cout << "Decoded Text: " << decodedText << endl;

    // Ensure the decoded text matches the original input text
    if (text == decodedText) {
        cout << "Encoding and Decoding successful!" << endl;
    } else {
        cout << "There was an error in Encoding/Decoding." << endl;
    }

    return 0;
}
