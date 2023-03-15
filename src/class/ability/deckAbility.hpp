#ifndef _DECKABILITY_HPP_
#define _DECKABILITY_HPP_

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "ability.hpp"
#include "abilityless.hpp"
#include "quadruple.hpp"
#include "quarter.hpp"
#include "reroll.hpp"
#include "reverse.hpp"
#include "swap.hpp"
#include "switch.hpp"
#include "noAbility.hpp"
#include "../game/gameManager.hpp"
#include "../game/game.hpp"
#include "../inventoryHolder/player.hpp"
using namespace std;

class DeckAbility {
    private:
        map<int, Ability*> aDeck;
    public:
        DeckAbility();                          /* Default Constructor */
        ~DeckAbility();                         /* Destructor */

        map<int, Ability*> getAbilityDeck();    /* Getter */
        void resetAbilityDeck();                /* Reset Ability Deck */
        void shuffleAbility(Game*);             /* Shuffle Ability Deck */
        void distributeAbility(Game*);          /* Distribute Ability Deck */
};

#endif