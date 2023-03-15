#ifndef GAME_HPP
#define GAME_HPP

#include "../utils/ListOfThing.hpp"
#include "Round.hpp"
#include <vector>
#include "inventory/CardsBank.hpp"
#include "inventory/AbilityCardsBank.hpp"
#include "Card/Combination/Combination.hpp"
#include "Card/Combination/High.hpp"
#include "Card/Combination/Pair.hpp"
#include "Card/Combination/TwoPair.hpp"
#include "Card/Combination/Flush.hpp"
#include "Card/Combination/ThreeOfKind.hpp"
#include "Card/Combination/FourOfKind.hpp"
#include "Card/Combination/FullHouse.hpp"
#include "Card/Combination/Straight.hpp"
#include "Card/Combination/StraightFlush.hpp"
#include "Card/LookupTable.hpp"
#include "../utils/sort.hpp"

using namespace std;

class Game {
    private:
        Round* round;
        int gameID;
        long long int prize;
        long long int maxPlayerPoint;
        CardsBank cardsBank;
        AbilityCardsBank abilityCardsBank;
        TableCard tablecard;
        bool ascending;
        
    public:
        Game(int);
        int startGame(List<Player>&);
        void NextRound();
        CardsBank getCardsBank();
        AbilityCardsBank getAbilityCardsBank();
        void displayTitle(string title, string subtitle);
};

#endif
