#include "switch.hpp"
#include "../game/gameManager.hpp"

Switch::Switch() {
    this->power = "Switch";
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