#include "ProteinDatabase.h"
#include <iostream>
#include <fstream>
using namespace std;

namespace sdds {
    ProteinDatabase::ProteinDatabase() {
        setEmpty();
    }

    // Rule of three
    ProteinDatabase::ProteinDatabase(const ProteinDatabase& proteinDatabase) {
        *this = proteinDatabase;
    }

    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& proteinDatabase) {
        // Checking whether the object is the same
        if (this != &proteinDatabase) {
            // Deallocating previously allocated memory
            delete[] proteinSeqArr;

            // Shallow Copy
            arrSize = proteinDatabase.arrSize;

            // Deep Copy
            if (proteinDatabase.proteinSeqArr != nullptr) {
                proteinSeqArr = new string[arrSize];
                for (int i = 0; i < arrSize; i++) {
                    proteinSeqArr[i] = proteinDatabase.proteinSeqArr[i];
                }
            } else {
                proteinSeqArr = nullptr;
            }

        }

        return *this;
    }

    // Populates the current object n
    ProteinDatabase::ProteinDatabase(const char* filename) {
        string bufferText{};
        int index {0};

        // Creating a file pointer
        ifstream inFile(filename);

        if (inFile) {
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
                    proteinSeqArr[index - 1] += bufferText;
                } else {
                    index++;
                }
            }
        }
    }

    // Deallocates dynamic memory
    ProteinDatabase::~ProteinDatabase() {
        delete[] proteinSeqArr;
    }

    // Returns the number of protein sequences stored in the current object
    size_t ProteinDatabase::size() const {
        return arrSize;
    }

    // Returns a copy of the protein sequence at the index received as the function parameter
    std::string ProteinDatabase::operator[](size_t index) const {
        // Checking whether the index is invalid
        if (index > arrSize - 1 || arrSize == 0) {
            return "";
        }

        return proteinSeqArr[index];
    }

    // Initializes to empty state
    void ProteinDatabase::setEmpty() {
        arrSize = 0;
        proteinSeqArr = nullptr;
    }
}