#include "quadruple.hpp"
#include "../game/gameManager.hpp"

Quadruple::Quadruple() : Ability("QUADRUPLE") {}

void Quadruple::use(string power, GameManager* state) {
    if (this->power != power) {
        throw NoCardException(power);
    }
    else if (this->used) {
        throw UsedCardException(power);
    }
    else if (!isActive()) {
        throw AbilityOffException(power);
    }
    else {
        __uint128_t temp = state->getPrize();
        state->setPrize(temp * 4);
        cout << state->getFirstPlayer().getName() << " melakukan QUADRUPLE! Poin hadiah naik dari" << endl;
        state->printPrize(temp);
        cout << " menjadi ";
        state->printPrize(state->getPrize());
        cout << "!" << endl;
        this->used = true;
    }
}