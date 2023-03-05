#ifndef _SWAP_HPP_
#define _SWAP_HPP_

#include "ability.hpp"

class Swap : public Ability {
    private:
        string power;
        bool used;
    public:
        Swap();
        ~Swap();

        string getPower() const override;
        bool getUsage() const override;
        void use(string);
};

#endif