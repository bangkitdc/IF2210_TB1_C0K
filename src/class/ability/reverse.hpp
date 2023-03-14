#ifndef _REVERSE_HPP_
#define _REVERSE_HPP_

#include "ability.hpp"

class Reverse : public Ability {
    public:
        Reverse();
        void use(string, GameManager*);
};

#endif