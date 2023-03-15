#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_

#include <iostream>
#include <string>
#include "../exception/commandException.hpp"
using namespace std;

#pragma once
class GameManager;
class Player;

class Ability {
    protected:
        string power;
        bool used;
        bool active;
    public:
        Ability(string);                            /* Constructor */
        ~Ability();                                 /* Destructor */

        string getPower() const;                    /* Getter */
        void setActive(bool);                       /* Setter */

        bool isUsed() const;                        /* Validator */
        bool isActive() const;                      /* Validator */
        bool isInteger(const string &);             /* Validator */

        virtual void use(string, GameManager*) = 0; /* Implementor */
};

#endif