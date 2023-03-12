#ifndef _QUARTER_HPP_
#define _QUARTER_HPP_
#include "AbilityCommand.hpp"
#include "../Round.hpp"

class Quarter : public abilityCommand {
    private:

    public:
        Quarter();                          // default ctor
        Quarter(string, string, List<Player>);            // user defined ctor
        Quarter(const Quarter&);            // cctor
        Quarter& operator=(const Quarter&); // assignment
        ~Quarter();                         //  dtor

        void execute(int);
        bool continueToNextPlayer();

};

#endif