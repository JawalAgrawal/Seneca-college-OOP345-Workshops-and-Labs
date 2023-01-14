#include "FoodOrder.h"
#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

namespace sdds {
    FoodOrder::FoodOrder() {
        setEmpty();
    }

    FoodOrder::~FoodOrder() {
        deallocate();
    }

    // Reads a line in the text file and stores data in class
    std::istream& FoodOrder::read(std::istream& is) {
        if (is) {

            // Reading the customer name
            char temp[1024];
            is.getline(temp, 1024, ',');

            // Checking whether the customer name exists
            if (strlen(temp) > 0) {
                customerName = new char[strlen(temp) + 1];
                strcpy(customerName, temp);

                // Reading the Food Description
                char temp2[1024];
                is.getline(temp2, 1024, ',');
                foodDescription = new char[strlen(temp2) + 1];
                strcpy(foodDescription, temp2);

                // Reading the food price
                is >> foodPrice;
                is.ignore(1);

                // Reading whether there is any special pricing
                char temp3[1024];
                is.getline(temp3, 1024, '\n');
                if (temp3[0] == 'N') {
                    dailySpecial = false;
                } else if (temp3[0] == 'Y') {
                    dailySpecial = true;
                }
            } else {
                cout << "No Order" << endl;
                setEmpty();
            }

        }
        return is;
    }

    // Displays data
    void FoodOrder::display() const {
        // Creating a static variable in memory so that it lasts for the lifetime of this function
        static int counter = 1;

        // Only printing if the customer name exists
        if (customerName != nullptr) {
            cout
            << setw(2) << left << counter << ". "
            << setw(10) <<  customerName
            << "|" << setw(25) << foodDescription
            << "|" << setw(12) << fixed << setprecision(2) << (foodPrice)
            << "|" << setw(13) << right << (dailySpecial) << endl;
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