/*
*****************************************************************************
                              Movie.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 19 February 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <iostream>

namespace sdds {
    class Movie {
    private:
        std::string m_title {};
        size_t m_yearOfRelease {};
        std::string m_description {};
    public:
        // Default Constructor
        Movie() = default;

        // Extracts the information about the movie from the string and stores the tokens in the attributes
        Movie(const std::string& strMovie);

        // A query that returns the title of the movie
        const std::string& title() const;

        // Friend helper insertion operator
        friend std::ostream& operator<<(std::ostream& os, const Movie& movie);

        // Function calls the overloaded operator() on instance spellChecker, passing to it the movie title and description
        template<typename T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_title, m_description);
        }
    };
}

#endif // SDDS_MOVIE_H