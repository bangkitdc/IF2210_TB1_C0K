#ifndef _SWITCH_HPP_
#define _SWITCH_HPP_

#include "ability.hpp"
#include "../cardValue/card.hpp"
#include "../game/gameManager.hpp"

class Switch : public Ability {
    public:
        Switch();                       /* Default Constructor */
        void use(string, GameManager*); /* Implementor */
};

#endif