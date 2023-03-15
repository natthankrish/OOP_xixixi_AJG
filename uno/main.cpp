#include <iostream>
#include "class/Competition.cpp"
#include "class/Game.cpp"
#include "class/Round.cpp"
#include "utils/ListOfThing.cpp"
#include "class/inventory/Player.cpp"
#include "class/inventory/InventoryHolder.cpp"
#include "class/inventory/CardsBank.cpp"
#include "class/inventory/TableCard.cpp"
#include "class/Card/Card.cpp"
#include "class/Card/NumberCard.cpp"
#include "class/command/Throw.cpp"
#include "class/command/Command.cpp"
#include "class/command/OrdinaryCommand.cpp"
#include "class/command/CheckTable.cpp"
#include "class/command/Next.cpp"
#include "class/command/Pick.cpp"
// #include "class/command/Double.cpp"
// #include "class/command/Quadruple.cpp"
// #include "class/command/Quarter.cpp"
#include "class/command/MyCard.cpp"
// #include "class/command/ChangePlayerCard.cpp"
// #include "class/command/AbilityCommand.cpp"
// #include "class/command/Swap.cpp"
// #include "class/command/Switch.cpp"
// #include "class/command/Reroll.cpp"
// #include "class/command/Reverse.cpp"
// #include "class/command/Abilityless.cpp"


int main () {
    bool valid = false;
    do {
        Competition* competition = new Competition();
        competition->startCompetition();
        
        int choice;
        cout << "Apakah ingin memulai kembali permainan (0/1): ";
        cin >> choice;
        valid = choice;
    } while (valid);
    return 0;
}