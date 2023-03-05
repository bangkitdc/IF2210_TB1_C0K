#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_

#include <iostream>
#include <string>
using namespace std;

class Ability {
    public:
        virtual string getPower() const = 0;
        virtual bool getUsage() const = 0;
        virtual void use(string) = 0;
};

#endif