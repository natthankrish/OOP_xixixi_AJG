#ifndef CHECKPRIZE_HPP
#define CHECKPRIZE_HPP
#include "OrdinaryCommand.hpp"
class Round;

class CheckPrize : public OrdinaryCommand {
    private:

    public:
        CheckPrize(string, string);

        bool continueToNextPlayer();
        void execute(int&, Round);
};

#endif
