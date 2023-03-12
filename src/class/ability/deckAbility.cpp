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

void DeckAbility::shuffleAbility(GameManager* state) {
    // int i = 1;
    // for (Player& p : state->getPlayer()) {
    //     p.setAbility(aDeck[i]);
    //     cout << aDeck[i]->getPower() << " " << p.getAbility()->getPower() << "\n";
    //     i++;
    // }
    // for (Player& p : state->getPlayer()) {
    //     cout << p.getAbility()->getPower() << " ";
    // }
    // for (int i = 0; i < 7; i++) {
    //     state->getPlayer().at(i).ability = new Quadruple;
    //     // cout << aDeck[i+1] << "\n";
    //     // cout << state->getPlayer().at(i).ability->getPower() << " ";
    // }
    // cout << "\n";
    for (Player& p : state->getPlayer()) {
        p.ability = new Quadruple;
        cout << p.getAbility()->getPower() << " ";
    }
    cout << "\n";
    for (Player& p : state->getPlayer()) {
        // p.ability = new Quadruple;
        cout << p.getAbility()->getPower() << " ";
    }
    cout << "\n";
}