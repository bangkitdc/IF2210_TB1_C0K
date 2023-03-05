#ifndef _ABILITYLESS_HPP_
#define _ABILITYLESS_HPP_

#include "ability.hpp"

class AbilityLess : public Ability {
    private:
        string power;
        bool used;
    public:
        AbilityLess();
        ~AbilityLess();

        string getPower() const override;
        bool getUsage() const override;
        void use(string);
};

#endif