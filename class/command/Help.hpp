#ifndef HELP_HPP
#define HELP_HPP
#include "OrdinaryCommand.hpp"

class Help : public OrdinaryCommand {
    private:

    public:
        Help(string, string);

        bool continueToNextPlayer();
        void execute(int);      
};

#endif