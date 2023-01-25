#ifndef SDDS_PROTEINDATABASE_H
#define SDDS_PROTEINDATABASE_H

#include <iostream>

namespace sdds {
    class ProteinDatabase {
    private:
        int arrSize;
        // Array of strings
        std::string* proteinSeqArr;
    public:
        // Default Constructor
        ProteinDatabase();

        // Rule of three
        ProteinDatabase(const ProteinDatabase& proteinDatabase);
        ProteinDatabase& operator=(const ProteinDatabase& proteinDatabase);

        // Populates the current object
        ProteinDatabase(const char* filename);

        // Deallocates dynamic memory
        ~ProteinDatabase();

        // Returns the number of protein sequences stored in the current object
        size_t size() const;

        // Returns a copy of the protein sequence at the index received as the function parameter
        std::string operator[](size_t index) const;

        // Initializes to empty state
        void setEmpty();
    };
}

#endif // SDDS_PROTEINDATABASE_H
