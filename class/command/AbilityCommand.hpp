#ifndef _ABILITY_COMMAND_HPP_
#define _ABILITY_COMMAND_HPP_
#include "Command.hpp"

class abilityCommand : public Command {
    private:

    public:
        abilityCommand();                                   // default ctor
        abilityCommand(string, string);                     // user defined ctor
        abilityCommand(const abilityCommand&);              // cctor
        abilityCommand& operator=(const abilityCommand&);   // assignment
        ~abilityCommand();                                  //  dtor

        void execute();
};

#endif