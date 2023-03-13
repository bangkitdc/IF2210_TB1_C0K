#include "deckAbility.hpp"

DeckAbility::DeckAbility() {
    this->aDeck[1] = new AbilityLess;
    this->aDeck[2] = new Quadruple;
    this->aDeck[3] = new Quarter;
    this->aDeck[4] = new ReRoll;
    this->aDeck[5] = new Reverse;
    this->aDeck[6] = new Swap;
    this->aDeck[7] = new Switch;
}

DeckAbility::~DeckAbility() {
    auto it = this->aDeck.begin();

    while(it != this->aDeck.end()) {
        delete (it->second);
        ++it;
    }
    this->aDeck.clear();
}

map<int, Ability*> DeckAbility::getAbilityDeck() {
    return this->aDeck;
}

void DeckAbility::shuffleAbility(Game* state) {
    vector<int> keys = {1,2,3,4,5,6,7};

    auto rng = std::default_random_engine {};
    shuffle(keys.begin(), keys.end(), rng);

    int i = 0;
    for (Player& p : state->playerTurn) {
        p.setAbility(aDeck[keys[i]]);
        cout << p.getAbility()->getPower() << " ";
        i++;
    }
    cout << "\n";
}