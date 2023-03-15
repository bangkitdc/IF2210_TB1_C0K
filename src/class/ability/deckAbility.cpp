#include "deckAbility.hpp"

DeckAbility::DeckAbility() {
    for (int i=1; i<=7; i++) {
        this->aDeck[i] = new NoAbility;
    }
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
    for (auto it = this->aDeck.begin(); it != this->aDeck.end(); it++) {
        delete it->second;
    }
    this->aDeck.clear();

    vector<int> keys = {1,2,3,4,5,6,7};
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 g(seed);
    shuffle(keys.begin(), keys.end(), g);

    this->aDeck[keys[0]] = new AbilityLess;
    this->aDeck[keys[1]] = new Quadruple;
    this->aDeck[keys[2]] = new Quarter;
    this->aDeck[keys[3]] = new ReRoll;
    this->aDeck[keys[4]] = new Reverse;
    this->aDeck[keys[5]] = new Swap;
    this->aDeck[keys[6]] = new Switch;
}

void DeckAbility::distributeAbility(Game* state) {
    int i = 1;
    for (Player& p : state->playerTurn) {
        p.setAbility(aDeck[i]);
        // cout << p.getAbility()->getPower() << " ";
        i++;
    }
    // cout << "\n";
}