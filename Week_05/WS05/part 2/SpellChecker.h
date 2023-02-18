/*
*****************************************************************************
                              SpellChecker.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 19 February 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

#include <iostream>

namespace sdds {
    const unsigned int ARR_SIZE = 6;
    class SpellChecker {
    private:
        std::string m_badWords[ARR_SIZE] {};
        std::string m_goodWords[ARR_SIZE] {};
        size_t m_replacements[ARR_SIZE] { 0 }; // Parallel array to keep track of the number of replacements of each bad word
    public:
        SpellChecker() = default;

        // Loads the content of the file into the attributes
        SpellChecker(const char* filename);

        // Searches text and replaces any misspelled word with the correct version
        void operator()(std::string& text);

        // Inserts into the parameter how many times each misspelled word has been replaced by the correct word using the current instance
        void showStatistics(std::ostream& out) const;

        // Finds out how many times each misspelled word has been replaced by the correct word using the current instance
    };
}

#endif // SDDS_SPELLCHECKER_H