#ifndef GAME_HPP
#define GAME_HPP

#include "../utils/ListOfThing.hpp"
#include "Round.hpp"
#include <vector>
#include "inventory/CardsBank.hpp"

using namespace std;

class Game {
    private:
        Round* round;
        int gameID;
        CardsBank cardsBank;
        TableCard tablecard;
        
    public:
        Game(int);
        int startGame(List<Player>&);
        CardsBank getCardsBank();
        void displayTitle(string title, string subtitle);
};

#endif
