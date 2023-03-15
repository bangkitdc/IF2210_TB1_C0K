#ifndef _NOABILITY_HPP_
#define _NOABILITY_HPP_

#include "ability.hpp"
#include "../game/gameManager.hpp"

class NoAbility : public Ability {
    public:
        NoAbility();                    /* Default Constructor */
        void use(string, GameManager*); /* Implementor */
};

#endif