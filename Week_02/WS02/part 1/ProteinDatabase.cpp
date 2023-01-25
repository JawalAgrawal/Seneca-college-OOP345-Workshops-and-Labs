#include "ProteinDatabase.h"
#include <iostream>
#include <fstream>
using namespace std;

namespace sdds {
    ProteinDatabase::ProteinDatabase() {
        setEmpty();
    }

    // Populates the current object n
    ProteinDatabase::ProteinDatabase(const char* filename) {
        string bufferText;
        int index = 0;

        // Creating a file pointer
        ifstream inFile(filename);

        // Reading the file and counting the number of protein sequences
        while (inFile) {
            char ch = inFile.get();
            if (ch == '>') {
                arrSize++;
            }
        }

        // Reset the file pointer
        inFile.clear();
        inFile.seekg(0);

        // Reading the file again and assigning values
        // Dynamically allocating memory for array of strings
        proteinSeqArr = new string[arrSize];

        while (getline(inFile, bufferText)) {
            if (bufferText[0] != '>') {
                proteinSeqArr[index - 1] = bufferText;
            } else {
                index++;
            }
        }

    }

    // Deallocates dynamic memory
    ProteinDatabase::~ProteinDatabase() {
        delete[] proteinSeqArr;
        proteinSeqArr = nullptr;
    }

    // Returns the number of protein sequences stored in the current object
    size_t ProteinDatabase::size() const {
        return arrSize;
    }

    // Returns a copy of the protein sequence at the index received as the function parameter
    std::string ProteinDatabase::operator[](size_t index) const {
        return proteinSeqArr[index];
    }

    // Initializes to empty state
    void ProteinDatabase::setEmpty() {
        arrSize = 0;
        proteinSeqArr = nullptr;
    }
}