#include "class/Competition.cpp"
#include "class/Game.cpp"
#include "class/Round.cpp"
#include "utils/ListOfThing.cpp"
#include "class/inventory/Player.cpp"
#include "class/inventory/InventoryHolder.cpp"

int main () {
    Competition* competition = new Competition();
    competition->startCompetition();

    return 0;
}