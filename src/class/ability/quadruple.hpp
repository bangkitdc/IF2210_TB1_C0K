#ifndef _QUADRUPLE_HPP_
#define _QUADRUPLE_HPP_

#include "ability.hpp"

class Quadruple : public Ability {
    public:
        Quadruple();
        void use(string, GameManager*);
};

#endif