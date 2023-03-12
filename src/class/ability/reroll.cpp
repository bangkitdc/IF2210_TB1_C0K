#include "reroll.hpp"
#include "../game/gameManager.hpp"

ReRoll::ReRoll() {
    this->power = "ReRoll";
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