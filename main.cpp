#include <iostream>
#include "class/Competition.cpp"
#include "class/Game.cpp"
#include "class/Round.cpp"
#include "utils/ListOfThing.cpp"
#include "class/inventory/Player.cpp"
#include "class/inventory/InventoryHolder.cpp"
#include "class/inventory/CardsBank.cpp"
#include "class/inventory/AbilityCardsBank.cpp"
#include "class/inventory/TableCard.cpp"
#include "class/Card/Card.cpp"
#include "class/Card/NumberCard.cpp"
#include "class/Card/AbilityCard.cpp"
#include "class/command/CheckPrize.cpp"
#include "class/command/Command.cpp"
#include "class/command/OrdinaryCommand.cpp"
#include "class/command/Help.cpp"
#include "class/command/Next.cpp"
#include "class/command/Half.cpp"
#include "class/command/Double.cpp"
#include "class/command/Quadruple.cpp"
#include "class/command/Quarter.cpp"
#include "class/command/MyCard.cpp"
#include "class/command/ChangeCard.cpp"
#include "class/command/AbilityCommand.cpp"
#include "class/command/Swap.cpp"
#include "class/command/Switch.cpp"
#include "class/command/Reroll.cpp"
#include "class/command/Reverse.cpp"
#include "class/command/Abilityless.cpp"
#include "class/command/CheckTableCard.cpp"


int main () {
    Competition* competition = new Competition();
    competition->startCompetition();

    return 0;
}