#ifndef _DOUBLE_HPP_
#define _DOUBLE_HPP_
#include "OrdinaryCommand.hpp"
#include "../inventory/AbilityCardsBank.hpp"
#include "../inventory/CardsBank.hpp"

class Double : public ordinaryCommand {
    private:

    public:
        Double();                           // default ctor
        Double(string, string);             // user defined ctor
        Double(const Double&);              // cctor
        Double& operator=(const Double&);   // assignment
        ~Double();                          //  dtor

        void execute(List<Player>&, int, int&, CardsBank&, AbilityCardsBank&);
        bool continueToNextPlayer();


};

#endif