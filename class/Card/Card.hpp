#ifndef __CARD_HPP__
#define __CARD_HPP__
#include <string>

using namespace std;
class Card
{
    protected:
        string cardType;
        int value;
    public:
        void setCardType(string);
        string getCardType();
        void setValue(int);
        int getValue();
};


#endif