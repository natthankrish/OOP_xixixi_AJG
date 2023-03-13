#ifndef _ABILITY_COMMAND_HPP_
#define _ABILITY_COMMAND_HPP_
#include "Command.hpp"
#include "../inventory/Player.hpp"
#include "../../utils/ListOfThing.hpp"
#include "../Round.hpp"

class AbilityCommand : public Command {
    public:
        AbilityCommand(string, string);                     // user defined ctor
        virtual void execute(int);
        virtual bool continueToNextPlayer();
};

#endif