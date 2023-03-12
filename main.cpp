#include <iostream>
#include "class/Competition.cpp"
#include "class/Game.cpp"
#include "class/Round.cpp"
#include "utils/ListOfThing.cpp"
#include "class/inventory/Player.cpp"
#include "class/inventory/InventoryHolder.cpp"
#include "class/inventory/CardsBank.cpp"
#include "class/inventory/AbilityCardsBank.cpp"
#include "class/Card/Card.cpp"
#include "class/Card/NumberCard.cpp"
#include "class/Card/AbilityCard.cpp"

int main () {
    Competition* competition = new Competition();
    competition->startCompetition();

    return 0;
}