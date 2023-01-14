#include "FoodOrder.h"
#include <sstream>
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
            char temp[1024];
            is.getline(temp, 1024, ',');

//            if (customerName) {
//                delete[] customerName;
//                customerName = nullptr;
//            }

            if (is) {
                customerName = new char[strlen(temp) + 1];
                strcpy(customerName, temp);
            }

        }
        return is;
    }

    void FoodOrder::display() const {
//        cout << customerName << foodDescription << foodPrice << dailySpecial << endl;
        cout << customerName << endl;

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