#ifndef __NUMBERCARD_HPP__
#define __NUMBERCARD_HPP__
#include "Card.hpp"
#include <iostream>
#include <string>

using namespace std;

class NumberCard : public Card {
    private:
        int number;
        string color;

    public:
        NumberCard();
        NumberCard(int, string);
        int getNumber() const;
        void setNumber(int);
        string getColor() const;
        void setColor(string);
        void setColor(int);
        bool operator==(const NumberCard&);
        bool operator!=(const NumberCard&);
        bool operator<(NumberCard&) const;
        bool operator>(NumberCard&) const;
        friend ostream& operator<< (ostream&, NumberCard);
};


#endif