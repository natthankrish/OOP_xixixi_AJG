#ifndef MYCARD_HPP
#define MYCARD_HPP
#include "OrdinaryCommand.hpp"

class MyCard : public ordinaryCommand {
    private:

    public:
        MyCard(string, string);

        bool continueToNextPlayer();
        void execute(List<Player>&, int, int&);
};

#endif
