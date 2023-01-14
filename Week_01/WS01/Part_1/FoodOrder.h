#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H

#include <iostream>

double g_taxrate;
double g_dailydiscount;

namespace sdds {
    class FoodOrder {
    private:
        char customerName[10];
        char foodDescription[25];
        double foodPrice;
        bool dailySpecial;

        void setEmpty();

    public:
        FoodOrder();
        std::istream& read(std::istream& is);
        void display() const;
    };
}

#endif // SDDS_FOODORDER_H