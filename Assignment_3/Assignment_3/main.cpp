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

    // find fequency
    // build tree
    // encode

    writeFile(fileName, data);
    cout << data;

    string encodedText = readFile(fileName);
    string decodedText = decodeCodes(encodedText, pq.top);
    cout << decodedText << endl;

    return 0;
}
