#ifndef _QUARTER_HPP_
#define _QUARTER_HPP_

#include "ability.hpp"

class Quarter : public Ability {
    private:
        string power;
        bool used;
    public:
        Quarter();
        ~Quarter();

        string getPower() const override;
        bool getUsage() const override;
        void use(string, GameManager*);
};

#endif