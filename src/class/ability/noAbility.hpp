#ifndef _NOABILITY_HPP_
#define _NOABILITY_HPP_

#include "ability.hpp"

class NoAbility : public Ability {
    public:
        NoAbility();
        void use(string, GameManager*);
};

#endif