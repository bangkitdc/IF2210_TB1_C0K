#include "noAbility.hpp"

NoAbility::NoAbility() : Ability("0") {}

void NoAbility::use(string power, GameManager* state) {
    throw NoAbilityException();
}