#include "quarter.hpp"
#include "../game/gameManager.hpp"

Quarter::Quarter() : Ability("QUARTER") {}

void Quarter::use(string power, GameManager* state) {
    if (this->power != power) {
        throw NoCardException(power);
    }
    else if (this->used) {
        throw UsedCardException(power);
    }
    else {
        int temp = state->getPrize();
        if (temp != 1) {
            state->setPrize(temp / 4);
            if (temp == 2) {
                state->setPrize(1);
            }
            cout << state->getFirstPlayer().getName() << " melakukan QUARTER! Poin hadiah turun dari" << endl;
            cout << temp << " menjadi " << state->getPrize() << "!" << endl;
        } else {
            cout << state->getFirstPlayer().getName() << " melakukan HALF! Sayangnya poin hadiah sudah bernilai";
            cout << temp << ". Poin hadiah tidak berubah.. Giliran dilanjut!" << endl;
        }
        
        this->used = true;
    }
}