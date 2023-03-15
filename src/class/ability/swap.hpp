#ifndef _SWAP_HPP_
#define _SWAP_HPP_

#include "ability.hpp"
#include "../inventoryHolder/player.hpp"
#include "../game/gameManager.hpp"

class Swap : public Ability {
    public:
        Swap();                         /* Default Constructor */
        void use(string, GameManager*); /* Implementor */
};

#endif