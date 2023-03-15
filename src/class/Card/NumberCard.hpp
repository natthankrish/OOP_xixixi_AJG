#ifndef __NUMBERCARD_HPP__
#define __NUMBERCARD_HPP__
#include "Card.hpp"
#include <string>
class NumberCard : public Card {
    private:
        int number;
        string color;

    public:
        NumberCard();
        NumberCard(int, string);
        NumberCard& operator=(const NumberCard& nc);
        int getNumber() const;
        void setNumber(int);
        string getColor() const;
        int getColorWeight() const;
        void setColor(string);
        bool operator==(const NumberCard&);
        bool operator!=(const NumberCard&);
    
};


#endif