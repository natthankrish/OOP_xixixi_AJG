#include <iostream>
#include "class/Competition.hpp"
#include "class/Game.hpp"
#include "class/Round.hpp"
#include "utils/ListOfThing.hpp"
#include "class/inventory/Player.hpp"
#include "class/inventory/InventoryHolder.hpp"
#include "class/inventory/CardsBank.hpp"
#include "class/inventory/AbilityCardsBank.hpp"
#include "class/inventory/TableCard.hpp"
#include "class/Card/Card.hpp"
#include "class/Card/NumberCard.hpp"
#include "class/Card/AbilityCard.hpp"
#include "class/Card/Combination/Combination.hpp"
#include "class/command/CheckPrize.hpp"
#include "class/command/Command.hpp"
#include "class/command/OrdinaryCommand.hpp"
#include "class/command/Help.hpp"
#include "class/command/Next.hpp"
#include "class/command/Half.hpp"
#include "class/command/Double.hpp"
#include "class/command/Quadruple.hpp"
#include "class/command/Quarter.hpp"
#include "class/command/MyCard.hpp"
#include "class/command/ChangeCard.hpp"
#include "class/command/AbilityCommand.hpp"
#include "class/command/Swap.hpp"
#include "class/command/Switch.hpp"
#include "class/command/Reroll.hpp"
#include "class/command/Reverse.hpp"
#include "class/command/Abilityless.hpp"
#include "class/command/CheckTableCard.hpp"

const double Combination::MAX_VALUE = 2;

int main () {
    Competition* competition = new Competition();
    competition->startCompetition();

    return 0;
}