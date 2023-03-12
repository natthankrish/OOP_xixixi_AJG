#ifndef __NUMBERCARD_HPP__
#define __NUMBERCARD_HPP__
#include "Card.hpp"
#include <string>
class NumberCard : Card
{
    private:
        int number;
        string color;

    public:
        NumberCard();
        NumberCard(int, string);
        int getNumber();
        void setNumber(int);
        string getColor();
        void setColor(string);
        bool operator==(const NumberCard&);
        bool operator!=(const NumberCard&);
    
};


#endif