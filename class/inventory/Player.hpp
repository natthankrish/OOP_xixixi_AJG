#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <utility>
#include <NumberCard.hpp>
#include "InventoryHolder.hpp"
#include "../../utils/ListOfThing.hpp"
#include "AbilityCard.hpp"

class Player : public InventoryHolder {
    private:
        int playerID;
        string name;
        int point;
        bool havePlayedThisRound;
        AbilityCard abilityCard;
        pair<NumberCard, NumberCard> playerCards;
        // Kombo bestKombo
    public:
        Player();
        Player(int, string, int, bool);
        bool gethavePlayed();
        bool sethavePlayed(bool);
        void updatePoint(int point);
        int getPoint();
        int getPlayerID();
        string getName();
        // void setPlayerCards();
        // void searchBestDeckCards();
        void operator+(const NumberCard&);
        void operator-(const NumberCard&);

};

#endif