#ifndef _DECKABILITY_HPP_
#define _DECKABILITY_HPP_

#include <iostream>
#include <map>
#include <vector>
#include "ability.hpp"
#include "abilityless.hpp"
#include "quadruple.hpp"
#include "quarter.hpp"
#include "reroll.hpp"
#include "reverse.hpp"
#include "swap.hpp"
#include "switch.hpp"
using namespace std;

class DeckAbility {
    private:
        map<int, Ability*> aDeck;
    public:
        DeckAbility();
        ~DeckAbility();

        map<int, Ability*> getAbilityDeck();
        void shuffleAbility();
        void giveAbility();
};

#endif