#ifndef _REROLL_HPP_
#define _REROLL_HPP_

#include "ability.hpp"

class ReRoll : public Ability {
    private:
        string power;
        bool used;
    public:
        ReRoll();
        ~ReRoll();

        string getPower() const override;
        bool getUsage() const override;
        void use(string);
};

#endif