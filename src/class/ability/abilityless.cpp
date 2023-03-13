#include "abilityless.hpp"
#include "../game/gameManager.hpp"

AbilityLess::AbilityLess() {
    this->power = "ABILITYLESS";
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
        throw NoCardException(power);
    }
    else if (this->used) {
        throw UsedCardException(power);
    }
    else {
        cout << "dipake ya sayang\n";
        this->used = true;
    }
}