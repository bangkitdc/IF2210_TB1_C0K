#ifndef _SWAP_HPP_
#define _SWAP_HPP_

#include "ability.hpp"
#include "../inventoryHolder/player.hpp"
class Swap : public Ability {
    private:
        string power;
        bool used;
    public:
        Swap();
        ~Swap();

        string getPower() const override;
        bool getUsage() const override;
        void use(string, GameManager*);
};

#endif