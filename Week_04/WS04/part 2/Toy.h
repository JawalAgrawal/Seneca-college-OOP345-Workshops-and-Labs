/*
*****************************************************************************
                              Toy.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 12 February 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_TOY_H
#define SDDS_TOY_H

#include <iostream>

namespace sdds {
    class Toy {
    private:
        int t_orderID{};
        std::string t_name {};
        int t_numberOfItems {};
        double t_price {};
        double t_hstPercentage{ 13 };
    public:
        // Default Constructor
        Toy() = default;

        // Responsible for extracting information about the toy and storing the tokens in the instance's attributes
        Toy(const std::string& toy);

        // Updates the number of items attribute with the received value
        void update(int numItems);

        // Insert the contents of a toy object into an ostream object
        friend std::ostream& operator<<(std::ostream& os, const Toy& toy);
    };
}

#endif //PART_1_TOY_H