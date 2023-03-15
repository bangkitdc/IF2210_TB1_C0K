#ifndef _QUADRUPLE_HPP_
#define _QUADRUPLE_HPP_

#include "ability.hpp"
#include <cstdint>
#include "../game/gameManager.hpp"

class Quadruple : public Ability {
    public:
        Quadruple();                    /* Default Constructor */
        void use(string, GameManager*); /* Implementor */
};

#endif