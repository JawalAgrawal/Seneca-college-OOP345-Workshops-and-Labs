/*
*****************************************************************************
                              Book.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 19 February 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <iostream>

namespace sdds {
    class Book {
    private:
        std::string m_author {};
        std::string m_title {};
        std::string m_countryOfPublication {};
        size_t m_yearOfPublication { 0 };
        double m_price { 0 };
        std::string m_description {};
    public:
        // A default constructor
        Book() = default;

        // Extracts the information about the book from the string by parsing it and stores the tokens in the object's attributes
        Book(const std::string& strBook);

        // Destructor
        virtual ~Book();

        // A query that returns the title of the book
        const std::string& title() const;

        // A query that returns the publication country
        const std::string& country() const;

        // A query that returns the publication year
        const size_t& year() const;

        // A function that returns the price by reference, allowing the client code to update the price
        double& price();

        // Friend helper insertion operator
        friend std::ostream& operator<<(std::ostream& os, const Book& book);

        // Calls the overloaded operator() on the instance spellChecker, passing to it the book description
        template <typename T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_description);
        }
    };
}

#endif // SDDS_BOOK_H