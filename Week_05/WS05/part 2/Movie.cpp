/*
*****************************************************************************
                              Movie.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 19 February 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Movie.h"
#include <iostream>
#include <iomanip>

namespace sdds {
    // Extracts the information about the movie from the string and stores the tokens in the attributes
    Movie::Movie(const std::string& strMovie) {
        // Initializing the start and the end index
        size_t startIndex {0};
        size_t endIndex = strMovie.find(',');

        // Storing the title
        m_title = strMovie.substr(startIndex, (endIndex - startIndex));
        startIndex = endIndex + 1;
        endIndex = strMovie.find(',', startIndex);
        // Erasing trailing and leading white spaces
        m_title.erase(0, m_title.find_first_not_of(" \t\r\n"));
        m_title.erase(m_title.find_last_not_of(" \t\r\n") + 1);

        // Storing the year of release
        m_yearOfRelease = std::stoi(strMovie.substr(startIndex, (endIndex - startIndex)));
        startIndex = endIndex + 1;
        endIndex = strMovie.find('\n', startIndex);

        // Storing the description of the movie
        m_description = strMovie.substr(startIndex, endIndex);
        // Erasing trailing and leading white spaces
        m_description.erase(0, m_description.find_first_not_of(" \t\r\n"));
        m_description.erase(m_description.find_last_not_of(" \t\r\n") + 1);
    }

    // A query that returns the title of the movie
    const std::string& Movie::title() const { return m_title; }

    // Friend helper insertion operator
    std::ostream& operator<<(std::ostream& os, const Movie& movie) {
        os << std::right << std::setw(40) << movie.m_title << " | ";
        os << std::setw(4) << movie.m_yearOfRelease << " | ";
        os << std::left << std::setw(40) << movie.m_description << "\n";
        return os;
    }
}