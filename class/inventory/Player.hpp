#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../Card/NumberCard.hpp"
#include "InventoryHolder.hpp"
#include "../../utils/ListOfThing.hpp"
#include "../Card/AbilityCard.hpp"

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
        void sethavePlayed(bool);
        void updatePoint(int point);
        int getPoint();
        int getPlayerID();
        string getName();
        void setName(string);
        AbilityCard getAbilityCard();
        // void setPlayerCards();
        // void searchBestDeckCards();
        void operator+(const NumberCard&);
        void operator+(const AbilityCard&);
        void operator-(const NumberCard&);
        void operator-(const AbilityCard&);
        NumberCard operator--();
        void seeCard();

};

#endif