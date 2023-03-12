#include "reverse.hpp"
#include "../game/gameManager.hpp"

Reverse::Reverse() {
    this->power = "Reverse";
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