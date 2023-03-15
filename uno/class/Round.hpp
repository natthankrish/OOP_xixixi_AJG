#ifndef ROUND_HPP
#define ROUND_HPP

#include "command/Command.hpp"
#include "command/OrdinaryCommand.hpp"
#include "command/Next.hpp"
#include "command/Throw.hpp"
#include "command/CheckTable.hpp"
#include "command/Pick.hpp"
#include "command/MyCard.hpp"

class Round {
    private:
        int roundID;
        int idxCurrentPlayer;
        int cardToPick;
        bool ascending;
        Command* command;

    public:
        // friend ordinaryCommand;
        Round(int,int);
        void nextPlayer(List<Player>&);
        void processCurrentPlayer(List<Player>&, CardsBank&, TableCard&);
        void initializeRound(List<Player>&, CardsBank&);
        int getRoundID();
        int getIdxCurrentPlayer();
        void startRound(List<Player>&, CardsBank&, TableCard&);
        void getCardToPick(List<Player>&, CardsBank&, TableCard&);
};

#endif