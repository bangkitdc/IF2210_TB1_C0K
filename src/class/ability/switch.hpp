#ifndef _SWITCH_HPP_
#define _SWITCH_HPP_

#include "ability.hpp"

class Switch : public Ability {
    private:
        string power;
        bool used;
    public:
        Switch();
        void use(string, GameManager*);
};

#endif