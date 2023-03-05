#ifndef _REVERSE_HPP_
#define _REVERSE_HPP_

#include "ability.hpp"

class Reverse : public Ability {
    private:
        string power;
        bool used;
    public:
        Reverse();
        ~Reverse();

        string getPower() const override;
        bool getUsage() const override;
        void use(string);
};

#endif