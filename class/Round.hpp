#ifndef ROUND_HPP
#define ROUND_HPP

#include "command/Command.hpp"
#include "command/OrdinaryCommand.hpp"
#include "inventory/Player.hpp"
#include "command/Next.hpp"
#include "command/Double.hpp"
#include "command/Half.hpp"
//#include "command/Quadruple.hpp"
#include "inventory/AbilityCardsBank.hpp"
#include "inventory/CardsBank.hpp"
#include "command/CheckPrize.hpp"
#include "command/Help.hpp"
#include "command/MyCard.hpp"
#include "command/ChangePlayerCard.hpp"

class Round {
    private:
        int roundID;
        int idxCurrentPlayer;
        int playerRemaining;
        Command* command;

    public:
        // friend ordinaryCommand;
        Round(int,int);
        void nextPlayer(List<Player>&);
        void processCurrentPlayer(List<Player>&, int&, CardsBank&, AbilityCardsBank&);
        void initializeRound(List<Player>&, CardsBank&, AbilityCardsBank&);
        int getRoundID();
        int getIdxCurrentPlayer();
        void startRound(List<Player>&, int&, CardsBank&, AbilityCardsBank&);
};

#endif