#ifndef _SWAP_HPP_
#define _SWAP_HPP_

#include "ability.hpp"
#include "../inventoryHolder/player.hpp"
class Swap : public Ability {
    public:
        Swap();
        void use(string, GameManager*);
};

#endif