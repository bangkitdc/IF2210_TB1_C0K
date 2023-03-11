#include "ability.hpp"
#include "abilityless.hpp"
#include "quadruple.hpp"
#include "quarter.hpp"
#include "reroll.hpp"
#include "reverse.hpp"
#include "swap.hpp"
#include "switch.hpp"
#include <map>
#include <iostream>
using namespace std;


int main() {
    map<int, Ability*> deck;
    
    deck[1] = new AbilityLess;
    deck[2] = new Quadruple;
    deck[3] = new Quarter;
    deck[4] = new ReRoll;
    deck[5] = new Reverse;
    deck[6] = new Swap;
    deck[7] = new Switch;
    
    auto it = deck.begin();

    while(it != deck.end()) {
        cout << it->first << " " << it->second->getPower() << endl;
        ++it;
    }

    deck[1]->use("ReRoll");
    deck[1]->use("AbilityLess");
    deck[1]->use("AbilityLess");

    return 0;
}