#include "quarter.hpp"
#include "../game/gameManager.hpp"
#include "../inventoryHolder/player.hpp"

Quarter::Quarter() {
    this->power = "Quarter";
    this->used = false;
}

Quarter::~Quarter() { }

string Quarter::getPower() const {
    return this->power;
}

bool Quarter::getUsage() const {
    return this->used;
}

void Quarter::use(string power, GameManager* state) {
    if (this->power != power) {
        cout << "bukan punyalu goblok\n";
    }
    else if (this->used) {
        cout << "udah dipake kontol\n";
    }
    else {
        int temp = state->getPrize();
        state->setPrize(temp / 4);
        cout << state->getPlayer().front().getName() << " melakukan QUARTER! Poin hadiah naik dari" << endl;
        cout << temp << " menjadi " << state->getPrize() << "!" << endl;
        this->used = true;
    }
}