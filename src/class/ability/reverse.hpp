#ifndef _REVERSE_HPP_
#define _REVERSE_HPP_

#include "ability.hpp"

class Reverse : public Ability {
    private:
        string power;
        bool used;
    public:
        Reverse();
        void use(string, GameManager*);
};

#endif