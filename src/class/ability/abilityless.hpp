#ifndef _ABILITYLESS_HPP_
#define _ABILITYLESS_HPP_

#include "ability.hpp"

class AbilityLess : public Ability {
    public:
        AbilityLess();
        void use(string, GameManager*);
};

#endif