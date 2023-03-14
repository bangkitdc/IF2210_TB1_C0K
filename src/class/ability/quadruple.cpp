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
    else {
        int temp = state->getPrize();
        state->setPrize(temp * 4);
        cout << state->getFirstPlayer().getName() << " melakukan QUADRUPLE! Poin hadiah naik dari" << endl;
        cout << temp << " menjadi " << state->getPrize() << "!" << endl;
        this->used = true;
    }
}