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
            return "Ets, tidak bisa. Kamu tidak punya kartu Ability " 
            + this->ability + ".\nSilahkan lakukan perintah lain.";
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
            return "Ets, Kamu udah pakai kartu Ability " 
            + this->ability + ".\nSilahkan lakukan perintah lain.";
        }
};

class NoAbilityException : public BaseException {
    public:
        NoAbilityException() {}
        const string what() const noexcept {
            return "Kartu Ability belum dibagiin nih :).\nSilahkan lakukan perintah lain.";
        }
};

class AbilityOffException : public BaseException {
    private:
        string ability;
    public:
        AbilityOffException(string ability) {
            this->ability = ability;
        }
        const string what() const noexcept {
            return "Oops, kartu ability " + this->ability + 
            " milikmu telah dimatikan sebelumnya :(.\nSilahkan lakukan perintah lain.";
        }
};

#endif