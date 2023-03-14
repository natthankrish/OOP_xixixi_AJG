#ifndef ROUND_HPP
#define ROUND_HPP

#include "command/Command.hpp"
#include "command/OrdinaryCommand.hpp"
#include "inventory/Player.hpp"
#include "command/Next.hpp"
#include "command/Double.hpp"
#include "command/Half.hpp"
#include "command/Quadruple.hpp"
#include "command/Quarter.hpp"
#include "inventory/AbilityCardsBank.hpp"
#include "inventory/CardsBank.hpp"
#include "command/CheckPrize.hpp"
#include "command/Help.hpp"
#include "command/MyCard.hpp"
#include "command/Swap.hpp"
#include "command/Switch.hpp"
#include "command/Reroll.hpp"
#include "command/Reverse.hpp"
#include "command/Abilityless.hpp"
#include "command/CheckTableCard.hpp"
#include "command/ChangeCard.hpp"

class Round {
    private:
        int roundID;
        int idxCurrentPlayer;
        int playerRemaining;
        Command* command;

    public:
        // friend ordinaryCommand;
        Round(int,int);
        void nextPlayer(List<Player>&, bool&);
        void processCurrentPlayer(List<Player>&, int&, CardsBank&, AbilityCardsBank&, TableCard&, bool&);
        void initializeRound(List<Player>&, CardsBank&, AbilityCardsBank&, TableCard&);
        int getRoundID();
        int getIdxCurrentPlayer();
        void startRound(List<Player>&, int&, CardsBank&, AbilityCardsBank&, TableCard&, bool&);
        string capitalize(string command);
        string displayTitle(string title, string subtitle);
};

#endif