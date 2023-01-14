#include "FoodOrder.h"

#include <iostream>
using namespace std;

namespace sdds {
    FoodOrder::FoodOrder() {
        setEmpty();
    }

    std::istream& FoodOrder::read(std::istream& is) {
        if (is) {
//            <Customer Name>,<Order Description>,<Price>,<Daily Special Status>[newline]
            string name;
            string orderDescription;
            string price;
            string dailySpecialStatus;
            string line;
        }
        return is;
    }

    void FoodOrder::display() const {
        cout << "2 . Julian    |8 Piece Sushi Set        |9.03        |         7.88" << endl;
    }

    void FoodOrder::setEmpty() {
        customerName[0] = '\0';
        foodDescription[0] = '\0';
        foodPrice = 0;
        dailySpecial = false;
    }
}