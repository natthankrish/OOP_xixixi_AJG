#ifndef CHECKPRIZE_HPP
#define CHECKPRIZE_HPP
#include "OrdinaryCommand.hpp"

class CheckPrize : public ordinaryCommand {
    private:

    public:
        CheckPrize(string, string, List<Player>);

        bool continueToNextPlayer();
        void execute(int);
};

#endif
