#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_

#include <iostream>
#include <string>
using namespace std;

class Ability {
    protected:
        string power;
        bool usage;

    public:
        Ability();
        Ability(string, bool);
        ~Ability();

        void setPower(string);
        virtual string getPower() const;
        void setUsage(bool);
        bool getUsage() const;

        void Double();
        void Half();
        void ReRoll();
        void Quadruple();
        void Quarter();
        void Reverse();
        void Swap();
        void Switch();
        void AbilityLess();
};

#endif