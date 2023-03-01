#ifndef COMPETITION_HPP
#define COMPETITION_HPP

#include "Game.hpp"

class Competition {
    private:
        Game* currentGame;
    public:
        Competition();
        void startCompetition();
};

#endif