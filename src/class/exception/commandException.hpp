#ifndef _COMMANDEXCEPTION_HPP_
#define _COMMANDEXCEPTION_HPP_

#include "exception.hpp"
#include <algorithm>
#include <string>
using namespace std;

class InvalidCommandException : public BaseException {
    private:
        string command;
    public:
        InvalidCommandException(string command) {
            this->command = command;
        }

        const string what() const noexcept {
            return "Command " + this->command + " is invalid.";
        }
};

class NoCardException : public BaseException {
    private:
        string ability;
    public:
        NoCardException(string ability) {
            this->ability = ability;
        }

        const string what() const noexcept {
            return "Ets, tidak bisa. Kamu tidak punya kartu Ability " + this->ability + ".";
        }
};

class UsedCardException : public BaseException {
    private:
        string ability;
    public:
        UsedCardException(string ability) {
            this->ability = ability;
        }

        const string what() const noexcept {
            return "Ets, Kamu udah pakai kartu Ability " + this->ability + ".";
        }
};

#endif