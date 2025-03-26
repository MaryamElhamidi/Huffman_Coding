//
//  main.cpp
//  Assignment_3
//
//  Created by Maryam Elhamidi on 2025-03-21.
//

#include <iostream>
using namespace std;

// --------------------------------------------------------
string decodeCodes(const string& code, HNode* root) {

    string decodedText = ""; 
    *HNode iteratorNode = root;

    for (char bit : code) {

        if (bit == '0')
        {
            i = i->left;
        }
        else if (bit == '1')
        {
            i = i->right;
        }

        if (i->left == nullptr && i->right == nullptr)
        {
            decodedText += i->character;
            i = root;
        }

        return decodedText;
    }
        
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
