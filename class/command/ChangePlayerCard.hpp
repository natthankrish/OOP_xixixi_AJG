#ifndef _CHANGEPLAYERCARD_HPP_
#define _CHANGEPLAYERCARD_HPP_
#include "OrdinaryCommand.hpp"


class ChangePlayerCard : public ordinaryCommand {
    private:

    public:
        ChangePlayerCard(string, string);             // user defined ctor

        void execute(List<Player>&, int, int&);
        bool continueToNextPlayer();


};

#endif