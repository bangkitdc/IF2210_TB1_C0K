#ifndef _QUARTER_HPP_
#define _QUARTER_HPP_

#include "ability.hpp"
#include <cstdint>
#include "../game/gameManager.hpp"

class Quarter : public Ability {
    public:
        Quarter();                      /* Default Constructor */
        void use(string, GameManager*); /* Implementor */
};

#endif