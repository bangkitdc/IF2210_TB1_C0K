#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_

#include <iostream>
#include <string>
#include "../exception/commandException.hpp"
// #include "../game/gameManager.hpp"
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
        Ability(string);
        ~Ability();

        string getPower() const;
        bool getUsage() const;
        bool isActive() const;
        virtual void use(string, GameManager*) = 0;
};

#endif