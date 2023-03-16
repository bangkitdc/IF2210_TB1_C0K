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
        cout << "\nMelakukan pembuangan kartu yang sedang dimiliki.\n";

        state->playerTurn.front().resetPlayerCard();
        state->playerTurn.front().setCardN(state->d, 2);

        cout << "Kamu mendapatkan 2 kartu baru yaitu:\n";
        state->playerTurn.front().displayPlayerCard(0);
        cout << " && ";
        state->playerTurn.front().displayPlayerCard(1);
        cout << endl;
        state->displayCardUI(state->getFirstPlayer().getCards(), 4);
        cout << endl;
        this->used = true;
    }
}