#ifndef _COMMANDEXCEPTION_HPP_
#define _COMMANDEXCEPTION_HPP_

#include "exception.hpp"
#include <string>
using namespace std;

class InvalidCommandException : public BaseException {
    private:
        string command;
    public:
        InvalidCommandException(string command) {
            this->command = command;
        }

        void displayMessage() const {
            cout << "Command " << this->command << " is invalid." << endl;
        }
};

class FailedCommandException : public BaseException {
    private:
        BaseException *exception;
        string command;
    public:
        FailedCommandException(BaseException *exception, string command) {
            this->exception = exception;
            this->command = command;
        }

        void displayMessage() const {
            cout << "Command " << this->command << " is failed." << endl;
            this->exception->displayMessage();
        }
};

#endif