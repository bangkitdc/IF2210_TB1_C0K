#ifndef _REROLL_HPP_
#define _REROLL_HPP_

#include "ability.hpp"
#include "../game/gameManager.hpp"

class ReRoll : public Ability {
    public:
        ReRoll();                       /* Default Constructor */
        void use(string, GameManager*); /* Implementor */
};

#endif