#include "ability.hpp"

Ability::Ability(string power) {
    this->power = power;
    this->used = false;
    this->active = true;
}

Ability::~Ability() {}

string Ability::getPower() const {
    return this->power;
}

bool Ability::getUsage() const {
    return this->used;
}

bool Ability::isActive() const {
    return this->active;
}