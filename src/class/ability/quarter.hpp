#ifndef _QUARTER_HPP_
#define _QUARTER_HPP_

#include "ability.hpp"
#include <cstdint>

class Quarter : public Ability {
    public:
        Quarter();
        void use(string, GameManager*);
};

#endif