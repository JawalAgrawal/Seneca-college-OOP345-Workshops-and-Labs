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
            throw "Bad file name!";
        }

        // Storing into the arrays
        std::string badWord;
        std::string goodWord;
        int count = 0;
        while (file >> badWord >> goodWord) {
            m_badWords[count] = badWord;
            m_goodWords[count] = goodWord;
            count++;
        }

        // Close the file
        file.close();
    }

    // Searches text and replaces any misspelled word with the correct version
    void SpellChecker::operator()(std::string& text) {
// Find all instances of the bad word in the text received and replace all of them. Loop within the line.
        size_t start{};
        for (size_t i = 0; i < ARR_SIZE; i++)
        {
            start = 0;
            while ((start = text.find(m_badWords[i], start)) != std::string::npos)
            {
                text.replace(start, m_badWords[i].length(), m_goodWords[i]);
                start += m_goodWords[i].length();
                m_replacements[i]++;
            }

        }
    }

    // Inserts into the parameter how many times each misspelled word has been replaced by the correct word using the current instance
    void SpellChecker::showStatistics(std::ostream& out) const {
        size_t index = 0;
        out << "Spellchecker Statistics" << "\n";
        for (auto& badWord: m_badWords) {
            out << std::right << std::setw(15) << badWord << ": " << m_replacements[index] << " replacements" << "\n";
            index++;
        }
    }
}