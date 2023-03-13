#include "reroll.hpp"
#include "../game/gameManager.hpp"

ReRoll::ReRoll() {
    this->power = "RE-ROLL";
    this->used = false;
}

ReRoll::~ReRoll() { }

string ReRoll::getPower() const {
    return this->power;
}

bool ReRoll::getUsage() const {
    return this->used;
}

void ReRoll::use(string power, GameManager* state) {
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