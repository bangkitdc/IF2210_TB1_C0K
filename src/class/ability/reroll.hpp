#ifndef _REROLL_HPP_
#define _REROLL_HPP_

#include "ability.hpp"

class ReRoll : public Ability {
    private:
        string power;
        bool used;
    public:
        ReRoll();
        void use(string, GameManager*);
};

#endif