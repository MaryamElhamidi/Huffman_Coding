//
//  file_handling.cpp
//  Assignment_3
//
//  Created by Maryam Elhamidi on 2025-03-21.
//

#include "file_handling.h"
#include <fstream>
#include <sstream>

string readFile(const string &fileName) {
    ifstream inputFile(fileName);
    if (!inputFile.is_open()){
         return "";
    }
    stringstream buffer;
    buffer << inputFile.rdbuf();
    inputFile.close();
    return buffer.str();
}

bool writeFile(const string &fileName, const string &data) {
    ofstream outputFile(fileName, ios::binary);
    if (!outputFile.is_open()){
         return false;
    }
    outputFile << data;
    outputFile.close();
    return true;
}
