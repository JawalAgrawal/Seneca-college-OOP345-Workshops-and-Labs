/*
*****************************************************************************
                              ProteinDatabase.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 25 January 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "ProteinDatabase.h"
#include <iostream>
#include <fstream>
using namespace std;

namespace sdds {
    // Rule of three
    ProteinDatabase::ProteinDatabase(const ProteinDatabase& proteinDatabase) {
        *this = proteinDatabase;
    }

    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& proteinDatabase) {
        // Checking whether the object is the same
        if (this != &proteinDatabase) {
            // Deallocating previously allocated memory
            delete[] proteinSeqArr;
            proteinSeqArr = nullptr;

            // Shallow Copy
            arrSize = proteinDatabase.arrSize;

            // Deep Copy
            if (proteinDatabase.proteinSeqArr != nullptr) {
                proteinSeqArr = new string[arrSize];
                for (size_t i = 0; i < arrSize; i++) {
                    proteinSeqArr[i] = proteinDatabase.proteinSeqArr[i];
                }
            }
        }

        return *this;
    }

    ProteinDatabase::ProteinDatabase(ProteinDatabase&& proteinDatabase) noexcept {
        *this = std::move(proteinDatabase);
    }

    ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& proteinDatabase) noexcept {
        if (this != &proteinDatabase) {
            delete[] proteinSeqArr;
            proteinSeqArr = proteinDatabase.proteinSeqArr;
            proteinDatabase.proteinSeqArr = nullptr;
            arrSize = proteinDatabase.arrSize;
            proteinDatabase.arrSize = 0;
        }

        return *this;
    }

    // Populates the current object n
    ProteinDatabase::ProteinDatabase(const char* filename) {
        string bufferText{};
        size_t index {0};

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

            inFile.ignore(1000, '\n');
            while (getline(inFile, bufferText)) {
                if (bufferText[0] != '>') {
                    proteinSeqArr[index] += bufferText;
                } else {
                    if (index < arrSize) index++;
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
}