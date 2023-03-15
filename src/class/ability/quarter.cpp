#include "quarter.hpp"

Quarter::Quarter() : Ability("QUARTER") {}

void Quarter::use(string power, GameManager* state) {
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
        if (temp != 1) {
            state->setPrize(temp / 4);
            if (temp == 2) {
                state->setPrize(1);
            }
            cout << state->getFirstPlayer().getName() << " melakukan QUARTER! Poin hadiah turun dari" << endl;
            state->printPrize(temp);
            cout << " menjadi ";
           state-> printPrize(state->getPrize());
            cout << "!" << endl;
        } else {
            cout << state->getFirstPlayer().getName() << " melakukan HALF! Sayangnya poin hadiah sudah bernilai 1. ";
            cout << "Poin hadiah tidak berubah.. Giliran dilanjut!" << endl;
        }
        
        this->used = true;
    }
}