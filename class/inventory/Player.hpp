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
        long long int point;
        bool havePlayedThisRound;
        AbilityCard abilityCard;
        bool abilityCardStatus;
        pair<NumberCard, NumberCard> playerCards;
        // Kombo bestKombo
    public:
        Player();
        Player(int, string, long long int, bool);
        Player& operator=(const Player&);
        bool gethavePlayed();
        void sethavePlayed(bool);
        void updatePoint(long long int point);
        long long int getPoint();
        int getPlayerID();
        string getName();
        void setName(string);
        void setAbilityCard(AbilityCard);
        bool getAbilityStatus();
        void setAbilityStatus(bool);
        AbilityCard getAbilityCard();
        // void setPlayerCards();
        // void searchBestDeckCards();
        void operator+(const NumberCard&);
        void operator+(const AbilityCard&);
        void operator-(const NumberCard&);
        AbilityCard operator-(const AbilityCard&);
        pair <NumberCard, NumberCard> getPairOfCards();
        NumberCard operator--();
        void seeCard();

};

#endif