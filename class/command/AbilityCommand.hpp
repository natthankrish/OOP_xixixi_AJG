#ifndef _ABILITY_COMMAND_HPP_
#define _ABILITY_COMMAND_HPP_
#include "Command.hpp"
#include "../inventory/Player.hpp"
#include "../../utils/ListOfThing.hpp"
#include "../Round.hpp"

class AbilityCommand : public Command {
    public:
        AbilityCommand();                                   // default ctor
        AbilityCommand(string, string);                     // user defined ctor
        AbilityCommand(const AbilityCommand&);              // cctor
        AbilityCommand& operator=(const AbilityCommand&);   // assignment
        ~AbilityCommand();                                  //  dtor

        virtual void execute(int);
        virtual bool continueToNextPlayer();

};

#endif