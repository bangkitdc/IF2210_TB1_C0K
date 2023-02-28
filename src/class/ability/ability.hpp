#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_

#include <iostream>
#include <string>
using namespace std;

class Ability {
    protected:
        
    public:
        Ability();
        ~Ability();
        virtual string getValue() const = 0;
};

#endif