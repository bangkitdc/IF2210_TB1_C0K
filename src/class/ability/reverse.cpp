#include "reverse.hpp"
#include "../game/gameManager.hpp"

Reverse::Reverse() {
    this->power = "REVERSE";
    this->used = false;
}

Reverse::~Reverse() { }

string Reverse::getPower() const {
    return this->power;
}

bool Reverse::getUsage() const {
    return this->used;
}

void Reverse::use(string power, GameManager* state) {
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