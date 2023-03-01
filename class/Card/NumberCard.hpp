#ifndef __NUMBERCARD.HPP__
#define __NUMBERCARD.HPP__
#include "Card.hpp"
#include <string>
class NumberCard : Card
{
    private:
        int number;
        string color;

    public:
        int getNumber();
        void setNumber(int);
        string getColor();
        void setColor(string);
    
};


#endif