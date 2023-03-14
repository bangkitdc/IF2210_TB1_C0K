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

bool Ability::isUsed() const {
    return this->used;
}

bool Ability::isActive() const {
    return this->active;
}

void Ability::setActive(bool act) {
    this->active = act;
}

bool Ability::isInteger(const string& str) {
    try {
        stoi(str);
        return true;
    }
    catch (const exception&) {
        return false;
    }
}