#include <iostream>
#include "class/Competition.hpp"
#include "class/Game.hpp"
#include "class/Round.hpp"
#include "utils/ListOfThing.hpp"
#include "class/inventory/Player.hpp"
#include "class/inventory/InventoryHolder.hpp"
#include "class/inventory/CardsBank.hpp"
#include "class/inventory/TableCard.hpp"
#include "class/Card/Card.hpp"
#include "class/Card/NumberCard.hpp"
#include "class/command/Throw.hpp"
#include "class/command/Command.hpp"
#include "class/command/OrdinaryCommand.hpp"
#include "class/command/CheckTable.hpp"
#include "class/command/Next.hpp"
#include "class/command/Pick.hpp"
#include "class/command/MyCard.hpp"
// #include "class/command/Double.hpp"
// #include "class/command/Quadruple.hpp"
// #include "class/command/Quarter.hpp"
// #include "class/command/ChangePlayerCard.hpp"
// #include "class/command/AbilityCommand.hpp"
// #include "class/command/Swap.hpp"
// #include "class/command/Switch.hpp"
// #include "class/command/Reroll.hpp"
// #include "class/command/Reverse.hpp"
// #include "class/command/Abilityless.hpp"


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