#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_

#include <iostream>
#include <string>
// #include "../game/gameManager.hpp"
using namespace std;

#pragma once
class GameManager;
class Player;

class Ability {
    public:
        virtual string getPower() const = 0;
        virtual bool getUsage() const = 0;
        virtual void use(string, GameManager*) = 0;
};

#endif