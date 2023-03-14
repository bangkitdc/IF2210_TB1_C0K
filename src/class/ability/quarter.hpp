#ifndef _QUARTER_HPP_
#define _QUARTER_HPP_

#include "ability.hpp"

class Quarter : public Ability {
    public:
        Quarter();
        void use(string, GameManager*);
};

#endif