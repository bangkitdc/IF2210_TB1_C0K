#include "swap.hpp"

Swap::Swap() {
    this->power = "Swap";
    this->used = false;
}

Swap::~Swap() { }

string Swap::getPower() const {
    return this->power;
}

bool Swap::getUsage() const {
    return this->used;
}

void Swap::use(string power) {
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