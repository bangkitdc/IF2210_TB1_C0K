#include "reroll.hpp"

ReRoll::ReRoll() : Ability("RE-ROLL") {}

void ReRoll::use(string power, GameManager* state) {
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
        state->playerTurn.front().cardsP = {};
        state->playerTurn.front().setCardN(state->d, 2);
        cout << "Melakukan pembuangan kartu yang sedang dimiliki.\n";
        cout << "Kamu mendapatkan 2 kartu baru yaitu:\n";
        state->playerTurn.front().displayPlayerCard(0);
        cout << " && ";
        state->playerTurn.front().displayPlayerCard(1);
        cout << endl << endl;
        this->used = true;
    }
}