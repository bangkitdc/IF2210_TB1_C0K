#ifndef _QUADRUPLE_HPP_
#define _QUADRUPLE_HPP_

#include "ability.hpp"

class Quadruple : public Ability {
    private:
        string power;
        bool used;
    public:
        Quadruple();
        void use(string, GameManager*);
};

#endif