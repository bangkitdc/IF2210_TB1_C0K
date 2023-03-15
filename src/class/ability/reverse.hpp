#ifndef _REVERSE_HPP_
#define _REVERSE_HPP_

#include <algorithm>
#include <deque>
#include "../game/gameManager.hpp"
#include "ability.hpp"

class Reverse : public Ability {
    public:
        Reverse();                      /* Default Constructor */
        void use(string, GameManager*); /* Implementor */
};

#endif