#include "quadruple.hpp"

Quadruple::Quadruple() {
    this->power = "Quadruple";
    this->used = false;
}

Quadruple::~Quadruple() { }

string Quadruple::getPower() const {
    return this->power;
}

bool Quadruple::getUsage() const {
    return this->used;
}

void Quadruple::use(string power) {
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