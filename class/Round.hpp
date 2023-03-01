#ifndef ROUND_HPP
#define ROUND_HPP

//#include "command/Command.hpp"
#include "inventory/Player.hpp"

class Round {
    private:
        int roundID;
        int idxCurrentPlayer;
        int playerRemaining;
        //Command command;
    public:
        Round(int,int);
        void nextPlayer(List<Player>&);
        void processCurrentPlayer(List<Player>&, int&);
        int getRoundID();
        void startRound(List<Player>&, int&);
};

#endif