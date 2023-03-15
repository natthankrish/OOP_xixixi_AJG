# IF2210_Object Oriented Programming
## *Tubes1_xixixi_AJG*


## **Table of Contents**
* [Program Description](#program-description)
* [Required Program](#required-program)
* [How to Run The Program](#how-to-run-the-program)
* [Progress Report](#progress-report)
* [Authors](#authors)
* [Folders and Files Description](#folders-and-files-description)

## **Program Description**
The constructed program is a 7-players card game. As the game starts, each players will have initially 0 point as the starting point. For each round of the game, the players will take turns to play. The goal of each round will be for players to take more and more points. Players will be using the card game to do several commands during the game. The card game itself consists of 4 type of colors. Sorted from the highest value, the colors are Red, Yellow, Blue, and Green. For each color types of cards, each card has the value of 1 until 13. Players can combine several combinations of the cards they have when playing the game. The game will be ended if a player has at least 2^32 points. Else, the game will be continued into several games and rounds. 

## **Required Program**
Here are the things needed to run the program: 
| No | Required Program | Reference Link |
|----|------------------|----------------|
| 1 | Windows Subsystem for Linux (WSL) | [WSL](https://learn.microsoft.com/en-us/windows/wsl/install) |
| 2 | Ubuntu 22.04.2 LTS | [Ubuntu](https://ubuntu.com/download/desktop) |
| 3 | C++ Compiler | [On Windows](https://www.freecodecamp.org/news/how-to-install-c-and-cpp-compiler-on-windows/) </br> [On Linux](https://www.codespeedy.com/how-to-install-cpp-on-linux/) |


 
## **How to Run The Program**

1. Clone this repository </br>
```sh
git clone https://github.com/natthankrish/OOP_xixixi_AJG.git
```

2. Change the current directory into the cloned repository </br>
```sh
cd OOP_xixixi_AJG
```


## **Progress Report**
| No | Module | Sub-module | Done |
|----|--------|-----------|-------|
| 1 | Card Deck | | &check; |
| 2 | Player Card and Table Card | | &check; |
| 3 | Game Round Robin System | | &check; |
| 4 | Reward Point | | &check; |
| 5 | Combinations  | High Card |  |
|   |               | Pair| &check; |
|   |               | Two Pairs | &check; |
|   |               | Three of a Kind |  |
|   |               | Straight | &check; |
|   |               | Flush | &check; |
|   |               | Full House |  |
|   |               | Four of a Kind | &check;  |
|   |               | Straight Flush |  |
| 6 | Abilities and Commands | Next |  |
|   |                        | Re-Roll |  |
|   |                        | Double / Quadruple |  |
|   |                        | Half / Quarter |  |
|   |                        | Reverse |  |
|   |                        | Swap Card |  |
|   |                        | Switch |  |
|   |                        | Abilityless |  |
| 7 |  Bonuses | Generic Class and Function |  |
|   |          | Another Card Game Implementation |  |


## **Authors** 
| Name | ID |
|-----|----|
| Melvin Kent Jonathan | 13521052 |
| Daniel Egiant Sitanggang | 13521056 |
| Ilham Akbar  | 13521068 |
| Juan Christopher Santoso | 13521116 | 
| Brigita Tri Carolina | 13521156 | 
| Antonio Natthan Krishna | 13521162 | 


## **Folders and Files Description**
    .
    ├─ .vscode                
    ├─ class 
        ├─ Card
            ├─ AbilityCard.cpp
            ├─ AbilityCard.hpp
            ├─ Card.cpp
            ├─ Card.hpp
            ├─ NumberCard.cpp
            ├─ NumberCard.hpp
        ├─ command
            ├─ AbilityCommand.cpp
            ├─ AbilityCommand.hpp
            ├─ Abilityless.cpp
            ├─ Abilityless.hpp
            ├─ CardException.hpp
            ├─ ChangePlayerCard.cpp
            ├─ ChangePlayerCard.hpp
            ├─ ChangeTableCard.cpp
            ├─ ChangeTableCard.hpp
            ├─ CheckPrize.cpp
            ├─ CheckPrize.hpp
            ├─ Command.cpp
            ├─ Command.hpp
            ├─ Double.cpp
            ├─ Double.hpp
            ├─ Half.cpp
            ├─ Half.hpp
            ├─ Help.cpp
            ├─ Help.hpp
            ├─ MyCard.cpp
            ├─ MyCard.hpp
            ├─ Next.cpp
            ├─ Next.hpp
            ├─ OrdinaryCommand.cpp
            ├─ OrdinaryCommand.hpp
            ├─ Quadruple.cpp
            ├─ Quadruple.hpp
            ├─ Quarter.cpp
            ├─ Quarter.hpp
            ├─ Reroll.cpp
            ├─ Reroll.hpp
            ├─ Reverse.cpp
            ├─ Reverse.hpp
            ├─ Swap.cpp
            ├─ Swap.hpp
            ├─ Switch.cpp
            ├─ Switch.hpp
        ├─ inventory
            ├─ AbilityCardsBank.cpp
            ├─ AbilityCardsBank.hpp
            ├─ CardsBank.cpp
            ├─ CardsBank.hpp
            ├─ InventoryException.hpp
            ├─ InventoryHolder.cpp
            ├─ InventoryHolder.hpp
            ├─ Player.cpp
            ├─ Player.hpp
            ├─ TableCard.cpp
            ├─ TableCard.hpp
        ├─ Competition.cpp
        ├─ Competition.hpp
        ├─ Round.cpp
        ├─ Round.hpp
    ├─ utils   
        ├─ ListOfThing.cpp
        ├─ ListOfThing.hpp
    ├─ main.cpp                
    └─ README.md
