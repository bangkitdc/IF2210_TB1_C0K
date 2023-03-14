#include "abilityless.hpp"
#include "../game/gameManager.hpp"

AbilityLess::AbilityLess() : Ability("ABILITYLESS") {}

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