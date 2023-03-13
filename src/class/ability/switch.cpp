#include "switch.hpp"
#include "../game/gameManager.hpp"

Switch::Switch() {
    this->power = "SWITCH";
    this->used = false;
}

Switch::~Switch() { }

string Switch::getPower() const {
    return this->power;
}

bool Switch::getUsage() const {
    return this->used;
}

void Switch::use(string power, GameManager* state) {
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