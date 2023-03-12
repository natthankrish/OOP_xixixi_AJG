#ifndef HELP_HPP
#define HELP_HPP
#include "OrdinaryCommand.hpp"

class Help : public ordinaryCommand {
    private:

    public:
        Help(string, string, List<Player>);

        bool continueToNextPlayer();
        void execute(Round, int);

};

#endif