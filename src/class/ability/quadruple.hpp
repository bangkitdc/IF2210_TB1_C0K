#ifndef _QUADRUPLE_HPP_
#define _QUADRUPLE_HPP_

#include "ability.hpp"

class Quadruple : public Ability {
    private:
        string power;
        bool used;
    public:
        Quadruple();
        ~Quadruple();

        string getPower() const override;
        bool getUsage() const override;
        void use(string, GameManager*);
};

#endif