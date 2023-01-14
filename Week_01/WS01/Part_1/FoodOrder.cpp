#include "FoodOrder.h"
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

namespace sdds {
    FoodOrder::FoodOrder() {
        setEmpty();
    }

    FoodOrder::~FoodOrder() {
        deallocate();
    }

    std::istream& FoodOrder::read(std::istream& is) {
        if (is) {

            // Reading the customer name
            char temp[1024];
            is.getline(temp, 1024, ',');

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

    void FoodOrder::display() const {
        if (customerName != nullptr) {
            cout << customerName << " " << foodDescription << " " << foodPrice << " " << dailySpecial << endl;
        }
    }

    void FoodOrder::setEmpty() {
        customerName = nullptr;
        foodDescription = nullptr;
        foodPrice = 0;
        dailySpecial = false;
    }

    void FoodOrder::deallocate() {
        delete[] customerName;
        delete[] foodDescription;
    }
}