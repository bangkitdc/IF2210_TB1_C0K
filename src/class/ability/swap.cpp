#include "swap.hpp"
#include "../game/gameManager.hpp"

Swap::Swap() {
    this->power = "SWAP";
    this->used = false;
}

Swap::~Swap() { }

string Swap::getPower() const {
    return this->power;
}

bool Swap::getUsage() const {
    return this->used;
}

void Swap::use(string power, GameManager* state) {
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