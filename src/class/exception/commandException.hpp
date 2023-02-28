#ifndef _COMMANDEXCEPTION_HPP_
#define _COMMANDEXCEPTION_HPP_

#include "exception.hpp"
#include <string>
using namespace std;

class CommandException : public BaseException {
    protected:
        static int numOfCommandException;
        string command;

    public:
        CommandException(string);                   // user-defined ctor
        CommandException(const CommandException &); // cctor

        string getCommandException();
        static int getNumOfCommandException();
        void displayMessage() const;
};

#endif