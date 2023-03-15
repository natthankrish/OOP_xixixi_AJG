#ifndef __CARD_HPP__
#define __CARD_HPP__
#include <string>

using namespace std;
class Card {
    protected:
        string cardType;
        int value;
    public:
        Card();
        Card(string, int);
        void setCardType(string);
        string getCardType() const;
        void setValue(int);
        int getValue() const;
        
};


#endif