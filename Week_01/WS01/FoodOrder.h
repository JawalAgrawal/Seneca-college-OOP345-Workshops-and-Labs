/*
*****************************************************************************
                              FoodOrder.h
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 14 January 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H

#include <iostream>

// Global Variables
extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds {
    class FoodOrder {
    private:
        char* customerName;
        char* foodDescription;
        double foodPrice;
        bool dailySpecial;

        // Initializes all attributes to safe empty state
        void setEmpty();

        // Frees all the dynamically allocated memory
        void deallocate();

    public:
        FoodOrder();
        ~FoodOrder();
        FoodOrder(const FoodOrder& foodOrder);
        FoodOrder& operator=(const FoodOrder& foodOrder);

        // Reads a line in the text file and stores data in class
        std::istream& read(std::istream& is);

        // Displays data
        void display() const;
    };
}

#endif // SDDS_FOODORDER_H