#include "quarter.hpp"
#include "../game/gameManager.hpp"
#include "../inventoryHolder/player.hpp"

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
        state->setPrize(temp / 4);
        cout << state->getFirstPlayer().getName() << " melakukan QUARTER! Poin hadiah naik dari" << endl;
        cout << temp << " menjadi " << state->getPrize() << "!" << endl;
        this->used = true;
    }
}