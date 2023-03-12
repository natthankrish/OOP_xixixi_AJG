#ifndef GAME_HPP
#define GAME_HPP

#include "../utils/ListOfThing.hpp"
#include "Round.hpp"
#include <vector>
#include "inventory/CardsBank.hpp"
#include "inventory/AbilityCardsBank.hpp"

using namespace std;

class Game {
    private:
        Round* round;
        int gameID;
        int prize;
        int maxPlayerPoint;
        CardsBank cardsBank;
        AbilityCardsBank abilityCardsBank;
    public:
        Game(int);
        int startGame(List<Player>&);
        void NextRound();
        CardsBank getCardsBank();
        AbilityCardsBank getAbilityCardsBank();
};

#endif
