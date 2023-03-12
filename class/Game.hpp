#ifndef GAME_HPP
#define GAME_HPP

#include "../utils/ListOfThing.hpp"
#include "Round.hpp"
#include <vector>
#include "Card/NumberCard.hpp"

using namespace std;

class Game {
    private:
        Round* round;
        int gameID;
        int prize;
        int maxPlayerPoint;
        vector<NumberCard> CardsBank;
    public:
        Game(int);
        int startGame(List<Player>&);
        void NextRound();
        void shuffleCards(vector<NumberCard>&);
        NumberCard getCardBankAt(int);
        vector<NumberCard> getCardBank();
};

#endif
