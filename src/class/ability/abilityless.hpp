#ifndef _ABILITYLESS_HPP_
#define _ABILITYLESS_HPP_

#include "ability.hpp"
#include "../game/gameManager.hpp"
#include "../exception/numberException.hpp"

class AbilityLess : public Ability {
    public:
        AbilityLess();                  /* Default Constructor */
        void use(string, GameManager*); /* Implementor */
};

#endif