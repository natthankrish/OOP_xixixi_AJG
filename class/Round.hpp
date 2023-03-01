#ifndef ROUND_HPP
#define ROUND_HPP

#include "command/Command.hpp"

class Round {
    private:
        int roundID;
        int idxCurrentPlayer;
        int playerRemaining;
        Command command;
    public:
        Round(int,int);
        void nextPlayer();
        void processCurrentPlayer();
        int getRoundID();
        void startRound();
};

#endif