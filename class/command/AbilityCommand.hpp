#ifndef _ABILITY_COMMAND_HPP_
#define _ABILITY_COMMAND_HPP_
#include "Command.hpp"
#include "inventory/Player.hpp"
#include "utils/ListOfThing.hpp"
#include "Round.hpp"

class abilityCommand : public Command {
    protected:
        List<Player> listPlayer;

    public:
        abilityCommand();                                   // default ctor
        abilityCommand(string, string, List<Player>);                     // user defined ctor
        abilityCommand(const abilityCommand&);              // cctor
        abilityCommand& operator=(const abilityCommand&);   // assignment
        ~abilityCommand();                                  //  dtor

        virtual void execute(Round, int);
};

#endif