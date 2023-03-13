#ifndef _QUADRUPLE_HPP_
#define _QUADRUPLE_HPP_
#include "AbilityCommand.hpp"

class Quadruple : public AbilityCommand {
    public:
        Quadruple(string, string);              // user defined ctor

        void execute(int, Round);
        bool continueToNextPlayer();
};

#endif