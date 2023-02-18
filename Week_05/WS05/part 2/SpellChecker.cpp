/*
*****************************************************************************
                              SpellChecker.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 19 February 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "SpellChecker.h"
#include <iostream>
#include <iomanip>
#include <fstream>

namespace sdds {
    // Loads the content of the file into the attributes
    SpellChecker::SpellChecker(const char* filename) {
        // Open the file for reading
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Failed to open " << filename << std::endl;
        }

        // Storing into the arrays
        std::string badWord;
        std::string goodWord;
        int count = 0;
        while (file >> badWord >> goodWord) {
            count++;
            m_badWords[count - 1] = badWord;
            m_goodWords[count - 1] = goodWord;
        }

        // Close the file
        file.close();
    }

    // Searches text and replaces any misspelled word with the correct version
    void SpellChecker::operator()(std::string& text) {
        size_t index = 0;
        for (auto& badWord: m_badWords) {
            size_t positionOfBadWord = 0;
            // Finding the bad words and replacing them with the correct ones
            if ((positionOfBadWord = text.find(badWord, positionOfBadWord)) >= 0) {
                text.replace(positionOfBadWord, badWord.length(), m_goodWords[index]);
                // Finds out how many times each misspelled word has been replaced by the correct word using the current instance
                m_replacements[index]++;
            }
            index++;
        }
    }

    // Inserts into the parameter how many times each misspelled word has been replaced by the correct word using the current instance
    void SpellChecker::showStatistics(std::ostream& out) const {
        size_t index = 0;
        for (auto& badWord: m_badWords) {
            out << std::right << std::setw(15) << badWord << ": " << m_replacements[index] << " replacements" << "\n";
            index++;
        }
    }
}