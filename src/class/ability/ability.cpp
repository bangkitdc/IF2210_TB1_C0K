#include "ability.hpp"

Ability::Ability() : Ability("-", false) { }

Ability::Ability(string power, bool usage) {
    this->power = power;
    this->usage = usage;
}

Ability::~Ability() { }

void Ability::setPower(string power) {
    this->power = power;
}

string Ability::getPower() const {
    return this->power;
}

void Ability::setUsage(bool usage) {
    this->usage = usage;
}

bool Ability::getUsage() const {
    return this->usage;
}
