#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../Card/NumberCard.hpp"
#include "InventoryHolder.hpp"
#include <vector>

class Player : public InventoryHolder {
    private:
        int playerID;
        string name;
        bool haveWin;
        vector<NumberCard> playerCards;

    public:
        Player();
        Player(int, string);
        bool gethaveWin();
        void sethaveWin(bool);
        int getPlayerID();
        string getName();
        void setName(string);
        vector<NumberCard>& getPlayerCard();
        void operator+(const NumberCard&);
        void operator-(const NumberCard&);
        vector<NumberCard> operator-(int card);
        void seeCard();
        bool look(int);
        void terminateThisRound();
};

#endif