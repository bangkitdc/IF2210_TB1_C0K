#include "abilityless.hpp"
#include "../game/gameManager.hpp"

AbilityLess::AbilityLess() {
    this->power = "AbilityLess";
    this->used = false;
}

AbilityLess::~AbilityLess() { }

string AbilityLess::getPower() const {
    return this->power;
}

bool AbilityLess::getUsage() const {
    return this->used;
}

void AbilityLess::use(string power, GameManager* state) {
    if (this->power != power) {
        cout << "bukan punyalu goblok\n";
    }
    else if (this->used) {
        cout << "udah dipake kontol\n";
    }
    else {
        cout << "dipake ya sayang\n";
        this->used = true;
    }
}