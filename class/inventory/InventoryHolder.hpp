#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <string>
#include <iostream>

using namespace std;

class InventoryHolder {
    private:
        string type;
        //List<Card> tableCard;
        
    public:
        InventoryHolder(string);
        void setType(string);
        string getType();

};

#endif
