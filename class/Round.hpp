#ifndef ROUND_HPP
#define ROUND_HPP

#include "command/Command.hpp"

class Round {
    private:
        int currentRound;
        int idxCurrentPlayer;
        int playerRemaining;
        Command command;
    public:
        Round(int,int,Command);
        void nextPlayer();
        void processCurrentPlayer();
};

#endif