// Name: Aryan Khurana
// Seneca Student ID: 145282216
// Seneca email: akhurana22@myseneca.ca
// Date of completion: 08 March 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"
#include <iostream>

namespace sdds {
    // Sets the field width of the current object to the value of parameter
    void Utilities::setFieldWidth(size_t newWidth) { m_widthField = newWidth; }

    // Returns the field width of the current object
    size_t Utilities::getFieldWidth() const { return m_widthField; }

    // Extracts a token from string str referred to by the first parameter.
    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
        size_t end_pos = str.find(m_delimiter, next_pos);
        std::string tokenExtracted {};

        tokenExtracted.erase(0, tokenExtracted.find_first_not_of((" \t\r\n")));
        tokenExtracted.erase(0, tokenExtracted.find_last_not_of((" \t\r\n")) + 1);

        if (end_pos != std::string::npos) {
            tokenExtracted = str.substr(next_pos, end_pos - next_pos);
            next_pos = end_pos + 1;
            more = true;
        } else {
            tokenExtracted = str.substr(next_pos);
            next_pos = str.length();
            more = false;
        }
        (tokenExtracted.length() > m_widthField) ? m_widthField = tokenExtracted.length() : m_widthField;
        if (tokenExtracted.empty()) { throw "ERROR: Token is empty!"; }

        return tokenExtracted;
    }

    // Sets the delimiter for this class to the character received
    void Utilities::setDelimiter(char newDelimiter) { m_delimiter = newDelimiter; }

    // Returns the delimiter for this class.
    char Utilities::getDelimiter() { return m_delimiter; }
}