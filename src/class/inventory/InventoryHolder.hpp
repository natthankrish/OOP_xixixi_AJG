#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <string>
#include <iostream>
#include <vector>
#include "../Card/Card.hpp"
#include "../Card/NumberCard.hpp"

using namespace std;

class InventoryHolder {
    private:
        string type;
        virtual void operator+(const NumberCard&) = 0;
        virtual void operator-(const NumberCard&) = 0;
        
    public:
        InventoryHolder(string);
        void setType(string);
        string getType();

};

#endif
