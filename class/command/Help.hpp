#ifndef HELP_HPP
#define HELP_HPP
#include "OrdinaryCommand.hpp"

class Help : public ordinaryCommand {
    private:

    public:
        Help(string, string);

        bool continueToNextPlayer();
        void execute(List<Player>&, int, int&);      
};

#endif