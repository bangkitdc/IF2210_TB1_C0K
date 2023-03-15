#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <iostream>
using namespace std;

class BaseException {
    public:
        virtual const string what() const = 0;    /* Display Message */
};

#endif