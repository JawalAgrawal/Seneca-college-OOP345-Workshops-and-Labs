/*
*****************************************************************************
                              Book.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 16 February 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Book.h"
#include <iostream>
#include <iomanip>

namespace sdds {
    // Extracts the information about the book from the string by parsing it and stores the tokens in the object's attributes
    Book::Book(const std::string& strBook) {
        // Initializing the start and the end index
        size_t startIndex {0};
        size_t endIndex = strBook.find(',');

        // Storing the author
        m_author = strBook.substr(startIndex, (endIndex - startIndex));
        startIndex = endIndex + 1;
        endIndex = strBook.find(',', startIndex);
        // Erasing trailing and leading white spaces
        m_author.erase(0, m_author.find_first_not_of(" \t\r\n"));
        m_author.erase(m_author.find_last_not_of(" \t\r\n") + 1);

        // Storing the title
        m_title = strBook.substr(startIndex, (endIndex - startIndex));
        startIndex = endIndex + 1;
        endIndex = strBook.find(',', startIndex);
        // Erasing trailing and leading white spaces
        m_title.erase(0, m_title.find_first_not_of(" \t\r\n"));
        m_title.erase(m_title.find_last_not_of(" \t\r\n") + 1);

        // Storing the country of publication
        m_countryOfPublication = strBook.substr(startIndex, (endIndex - startIndex));
        startIndex = endIndex + 1;
        endIndex = strBook.find(',', startIndex);
        // Erasing trailing and leading white spaces
        m_countryOfPublication.erase(0, m_countryOfPublication.find_first_not_of(" \t\r\n"));
        m_countryOfPublication.erase(m_countryOfPublication.find_last_not_of(" \t\r\n") + 1);

        // Storing the price of the book
        m_price = std::stod(strBook.substr(startIndex, (endIndex - startIndex)));
        startIndex = endIndex + 1;
        endIndex = strBook.find(',', startIndex);

        // Storing the year of publication
        m_yearOfPublication = std::stoi(strBook.substr(startIndex, (endIndex - startIndex)));
        startIndex = endIndex + 1;
        endIndex = strBook.find(',', startIndex);

        // Storing the description of the book
        m_description = strBook.substr(startIndex, endIndex);
        // Erasing trailing and leading white spaces
        m_description.erase(0, m_description.find_first_not_of(" \t\r\n"));
        m_description.erase(m_description.find_last_not_of(" \t\r\n") + 1);
    }

    // Destructor
    Book::~Book() {}

    // A query that returns the title of the book
    const std::string& Book::title() const { return m_title; }

    // A query that returns the publication country
    const std::string& Book::country() const { return m_countryOfPublication; }

    // A query that returns the publication year
    const size_t& Book::year() const { return m_yearOfPublication; }

    // A function that returns the price by reference, allowing the client code to update the price
    double& Book::price() { return m_price; }

    // Friend helper insertion operator
    std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << std::right << std::setw(20) << book.m_author << " | ";
        os << std::right << std::setw(22) << book.m_title << " | ";
        os << std::right << std::setw(5) << book.m_countryOfPublication << " | ";
        os << std::right << std::setw(4) << book.m_yearOfPublication << " | ";
        os << std::right << std::setw(6) << std::fixed << std::setprecision(2) << book.m_price << " | ";
        os << std::left << book.m_description;
        return os;
    }
}