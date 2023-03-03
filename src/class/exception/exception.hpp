#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <iostream>
// #include "commandException.hpp"
using namespace std;

class BaseException {
    public:
        virtual void displayMessage() const = 0;    // message display
};

#endif