#ifndef _QUADRUPLE_HPP_
#define _QUADRUPLE_HPP_
#include "AbilityCommand.hpp"

class Quadruple : public abilityCommand {
    private:

    public:
        Quadruple();                            // default ctor
        Quadruple(string, string, List<Player>);              // user defined ctor
        Quadruple(const Quadruple&);            // cctor
        Quadruple& operator=(const Quadruple&); // assignment
        ~Quadruple();                           //  dtor

        void execute(int, Round);
        bool continueToNextPlayer();

};

#endif