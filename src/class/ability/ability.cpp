#include "ability.hpp"

Ability::Ability(string power) {
    this->power = power;
    this->used = false;
}

Ability::~Ability() {}

string Ability::getPower() const {
    return this->power;
}

bool Ability::getUsage() const {
    return this->used;
}