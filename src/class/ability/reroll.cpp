#include "reroll.hpp"
#include "../game/gameManager.hpp"

ReRoll::ReRoll() : Ability("RE-ROLL") {}

void ReRoll::use(string power, GameManager* state) {
    if (this->power != power) {
        throw NoCardException(power);
    }
    else if (this->used) {
        throw UsedCardException(power);
    }
    else if (!isActive()) {
        throw AbilityOffException(power);
    }
    else {
        cout << "dipake ya sayang\n";
        this->used = true;
    }
}