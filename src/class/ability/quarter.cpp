#include "quarter.hpp"

Quarter::Quarter() {
    this->power = "Quarter";
    this->used = false;
}

Quarter::~Quarter() { }

string Quarter::getPower() const {
    return this->power;
}

bool Quarter::getUsage() const {
    return this->used;
}

void Quarter::use(string power) {
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