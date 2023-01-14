#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H

#include <iostream>

namespace sdds {
    class FoodOrder {
    private:
        char* customerName;
        char* foodDescription;
        double foodPrice;
        bool dailySpecial;

        void setEmpty();
        void deallocate();

    public:
        FoodOrder();
        ~FoodOrder();
        std::istream& read(std::istream& is);
        void display() const;
    };
}

#endif // SDDS_FOODORDER_H