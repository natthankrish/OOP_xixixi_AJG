#ifndef GAME_HPP
#define GAME_HPP

#include "../utils/ListOfThing.hpp"
#include "Round.hpp"

class Game {
    private:
        //List<Card> tableCard;
        Round* round;
        int gameID;
        int prize;
        int maxPlayerPoint;
    public:
        Game(int);
        int startGame(List<Player>&);
        void NextRound();
};

#endif
