#include "ProteinDatabase.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

namespace sdds {
    ProteinDatabase::ProteinDatabase() {
        setEmpty();
    }

    // Populates the current object n
    ProteinDatabase::ProteinDatabase(const char* filename) {
        // Buffer to read text into
        string proteinSequence;
        ifstream MyReadFile(filename);

        // Use a while loop together with the getline() function to read the file line by line
        while (getline (MyReadFile, proteinSequence)) {
            // Checking to only read sequences and not the description
            if (proteinSequence[0] != '>') {
                cout << proteinSequence << endl;
            }
        }

        // Close the file
        MyReadFile.close();
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