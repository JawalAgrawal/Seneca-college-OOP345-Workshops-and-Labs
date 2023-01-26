/*
*****************************************************************************
                              ProteinDatabase.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 25 January 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_PROTEINDATABASE_H
#define SDDS_PROTEINDATABASE_H

#include <iostream>

namespace sdds {
    class ProteinDatabase {
    private:
        size_t arrSize {0};
        // Array of strings
        std::string* proteinSeqArr {};
    public:
        // Default Constructor
        ProteinDatabase() = default;

        // Rule of five
        ProteinDatabase(const ProteinDatabase& proteinDatabase);
        ProteinDatabase(ProteinDatabase&& src) noexcept;
        ProteinDatabase& operator=(const ProteinDatabase& proteinDatabase);
        ProteinDatabase& operator=(ProteinDatabase&& proteinDatabase) noexcept;

        // Populates the current object
        ProteinDatabase(const char* filename);

        // Deallocates dynamic memory
        ~ProteinDatabase();

        // Returns the number of protein sequences stored in the current object
        size_t size() const;

        // Returns a copy of the protein sequence at the index received as the function parameter
        std::string operator[](size_t index) const;
    };
}

#endif // SDDS_PROTEINDATABASE_H
