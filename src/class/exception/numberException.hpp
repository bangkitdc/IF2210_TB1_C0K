#ifndef _NUMBEREXCEPTION_HPP_
#define _NUMBEREXCEPTION_HPP_

#include "exception.hpp"
#include <string>
using namespace std;

class InvalidNumberException : public BaseException {
    private:
        string num;
    public:
        InvalidNumberException(string num) {
            this->num = num;
        }

        const string what() const noexcept {
            return "Angka " + this->num + " tidak tersedia. Silahkan pilih angka yang tersedia!";
        }
};

class NotNumberException : public BaseException {
    private:
        string num;
    public:
        NotNumberException(string num) {
            this->num = num;
        }

        const string what() const noexcept {
            return this->num + " bukan Integer. Silahkan pilih angka yang tersedia!";
        }
};

#endif