//
//  file_handling.cpp
//  Assignment_3
//
//  Created by Maryam Elhamidi on 2025-03-21.
//

#include "file_handling.h"
#include <fstream>
#include <sstream>  // Included sstream to use stringstream for reading file content into a string

string readFile(const string &fileName) {
    ifstream inputFile(fileName);  // Open the file in read mode using an input file stream (ifstream)
    if (!inputFile.is_open()){     // Check if the file failed to open
         return ""; // Return an empty string if the file could not be opened
    }
    stringstream buffer; // Create a stringstream object to store file contents
    buffer << inputFile.rdbuf();  // Read the entire file content into the stringstream buffer
    inputFile.close();
    return buffer.str();  // Convert the stringstream content to a string and return it
}

bool writeFile(const string &fileName, const string &data) {
    ofstream outputFile(fileName, ios::binary);  // Open the file in write mode using an output file stream (ofstream)
    // Check if the file failed to open
    if (!outputFile.is_open()) {
         return false;  // Return false if the file could not be opened for writing
    }
    outputFile << data; // Write the provided data string to the file
    outputFile.close();
    return true;   // Return true to indicate successful writing to the file
}
