#ifndef COMPETITION_HPP
#define COMPETITION_HPP

#include "Game.hpp"
#include "inventory/Player.hpp"
#include "../utils/ListOfThing.hpp"

class Competition {
    private:
        Game* currentGame;
        List<Player>* ListOfPlayer;
    public:
        Competition();
        void startCompetition();
        void displayTitle(string title, string subtitle);
};

#endif