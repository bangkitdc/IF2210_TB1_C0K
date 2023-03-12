#include "quadruple.hpp"
#include "../game/gameManager.hpp"
#include "../inventoryHolder/player.hpp"

Quadruple::Quadruple() {
    this->power = "Quadruple";
    this->used = false;
}

Quadruple::~Quadruple() { }

string Quadruple::getPower() const {
    return this->power;
}

bool Quadruple::getUsage() const {
    return this->used;
}

void Quadruple::use(string power, GameManager* state) {
    cout << "KON\n";
    if (this->power != power) {
        cout << "bukan punyalu goblok\n";
    }
    else if (this->used) {
        cout << "udah dipake kontol\n";
    }
    else {
        int temp = state->getPrize();
        state->setPrize(temp * 4);
        cout << state->getPlayer().front().getName() << " melakukan QUADRUPLE! Poin hadiah naik dari" << endl;
        cout << temp << " menjadi " << state->getPrize() << "!" << endl;
        this->used = true;
    }
}