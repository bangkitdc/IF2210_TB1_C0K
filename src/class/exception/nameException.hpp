#ifndef _NAMEEXCEPTION_HPP_
#define _NAMEEXCEPTION_HPP_

#include "exception.hpp"
#include <string>
using namespace std;

class UsernameException : public BaseException {
    public:
        const string what() const noexcept {
            return "Masksimum panjang Username 10 karakter!\n";
        }
};

#endif