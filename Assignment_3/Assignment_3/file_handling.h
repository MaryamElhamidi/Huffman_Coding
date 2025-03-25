//
//  file_handling.h
//  Assignment_3
//
//  Created by Maryam Elhamidi on 2025-03-21.
//

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
using namespace std;

// Reads the entire content of the specified file and returns it as a string.
// Returns an empty string if the file cannot be opened.
string readFile(const string &fileName);

// Writes the provided data to the specified file in binary mode.
// Returns true if writing was successful, false otherwise.
bool writeFile(const string &fileName, const string &data);

#endif
