/*
*****************************************************************************
                              FoodOrder.cpp
Full Name  : Aryan Khurana
Student ID#: 145282216
Email      : akhurana22@myseneca.ca
Date of completion    : 14 January 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "FoodOrder.h"
#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

// Global Variables
double g_taxrate {0};
double g_dailydiscount {0};

namespace sdds {
    FoodOrder::FoodOrder() {
        setEmpty();
    }

    FoodOrder::~FoodOrder() {
        deallocate();
    }

    FoodOrder::FoodOrder(const FoodOrder& foodOrder) {
        *this = foodOrder;
    }

    FoodOrder& FoodOrder::operator=(const FoodOrder& foodOrder) {
        if (this != &foodOrder) {
            foodPrice = foodOrder.foodPrice;
            dailySpecial = foodOrder.dailySpecial;

            if (foodOrder.customerName != nullptr) {
                customerName = new char[strlen(foodOrder.customerName) + 1];
                strcpy(customerName, foodOrder.customerName);
            } else {
                customerName = nullptr;
            }

            if (foodOrder.foodDescription != nullptr) {
                foodDescription = new char[strlen(foodOrder.foodDescription) + 1];
                strcpy(customerName, foodOrder.foodDescription);
            } else {
                foodDescription = nullptr;
            }

        } else {
            customerName = nullptr;
            foodDescription = nullptr;
        }
        return *this;
    }

    // Reads a line in the text file and stores data in class
    std::istream& FoodOrder::read(std::istream& is) {
        if (is) {

            // Reading the customer name
            char temp[256];
            is.getline(temp, 256, ',');

            // Checking whether the customer name exists
            if (strlen(temp) > 0) {
                customerName = new char[strlen(temp) + 1];
                strcpy(customerName, temp);

                // Reading the Food Description
                char temp2[256];
                is.getline(temp2, 256, ',');
                foodDescription = new char[strlen(temp2) + 1];
                strcpy(foodDescription, temp2);

                // Reading the food price
                is >> foodPrice;
                is.ignore(1);

                // Reading whether there is any special pricing
                char temp3[256];
                is.getline(temp3, 256, '\n');
                if (temp3[0] == 'N') {
                    dailySpecial = false;
                } else if (temp3[0] == 'Y') {
                    dailySpecial = true;
                }
            } else {
                setEmpty();
            }

        }
        return is;
    }

    // Displays data
    void FoodOrder::display() const {
        // Creating a static variable in memory so that it lasts for the lifetime of this function
        static int counter {1};
        // Only printing if the customer name exists
        if (customerName != nullptr) {
            cout
            << setw(2) << left << counter << ". "
            << setw(10) <<  customerName
            << "|" << setw(25) << foodDescription
            << "|" << setw(12) << fixed << setprecision(2) << (foodPrice + (foodPrice * g_taxrate))
            << "|" << setw(13) << right;

            // Checking whether there is a discounted price to display
            if (dailySpecial) {
                cout << (foodPrice + (foodPrice * g_taxrate)) - g_dailydiscount << endl;
            } else {
                cout << endl;
            }

        } else {
            cout << setw(2) << left << counter << ". " << "No Order" << endl;
        }
        counter++;
    }

    // Initializes all attributes to safe empty state
    void FoodOrder::setEmpty() {
        customerName = nullptr;
        foodDescription = nullptr;
        foodPrice = 0;
        dailySpecial = false;
    }

    // Frees all the dynamically allocated memory
    void FoodOrder::deallocate() {
        delete[] customerName;
        delete[] foodDescription;
    }
}