#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <iostream>
using namespace std;

class BaseException {
    protected:
        static int numOfException;
        const int ID;

    public:
        BaseException(int);                         // user-defined ctor
        BaseException(const BaseException &);       // cctor

        static int getNumOfException();             // numOfException getter
        int getID() const;                          // ID getter

        virtual void displayMessage() const = 0;    // message display
};

#endif