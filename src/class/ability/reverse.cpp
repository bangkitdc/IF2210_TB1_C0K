#include "reverse.hpp"

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

void Reverse::use(string power) {
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