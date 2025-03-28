//
//  main.cpp
//  Assignment_3
//
//  Created by Maryam Elhamidi on 2025-03-21.
//

#include "huffman_tree.h"
#include "huffman_encoding.h"
#include "file_handling.h"
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    string fileName;
    string inputText;
    cout << "Please enter name of file to encode: " << endl;
    cin >> fileName;
    inputText = readFile(fileName); 
    while (inputText == "") {
        cout << "Please enter name of file to encode: " << endl;  
        cin >> fileName;
        inputText = readFile(fileName);
    }

    HNode* root = buildHuffmanTree(int (freq[256]);
    string encodedText = "";
    generateCodes(root, encodedText, string codes[256]);
    cout << encodedText << endl;
    while (writeFile(fileName, encodedText) == false) { 
        throw runtime_error("Could not open file"); 
        cout << "Please enter name of file to save Huffman code: " << endl; 
        cin >> fileName; 
        writeFile(fileName, encodedText); 
    }
    encodedText = readFile(fileName); 
    string decodedText = decodeCodes(encodedText, root); 
    cout << decodedText << endl; 

    return 0;
                                   }
                                   }
