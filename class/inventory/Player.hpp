#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "InventoryHolder.hpp"
#include "../../utils/ListOfThing.hpp"


class Player : public InventoryHolder {
    private:
        int playerID;
        string name;
        int point;
        bool havePlayedThisRound;
        //List<Card> playerCard
        //Kombo bestKombo
    public:
        Player();
        Player(int, string, int);
        void updatePoint(int point);
        int getPoint();
        int getPlayerID();
        string getName();
        void setPlayerCards();
        void searchBestDeckCards();
};

#endif