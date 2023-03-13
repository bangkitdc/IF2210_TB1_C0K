#include "switch.hpp"
#include "../game/gameManager.hpp"

Switch::Switch() {
    this->power = "SWITCH";
    this->used = false;
}

Switch::~Switch() { }

string Switch::getPower() const {
    return this->power;
}

bool Switch::getUsage() const {
    return this->used;
}

void Switch::use(string power, GameManager* state) {
    if (this->power != power) {
        throw NoCardException(power);
    }
    else if (this->used) {
        throw UsedCardException(power);
    }
    else {
        cout << "dipake ya sayang\n";
        cout << "p" << state->playerTurn.front().getId() << "melakukan switch!" << endl;
        cout << "Kartumu sekarang adalah :\n";
        state->playerTurn.front().displayPlayerCard(0);
        cout << " && ";
        state->playerTurn.front().displayPlayerCard(1);
        cout << endl;
        cout << "Silahkan pilih pemain yang kartunya ingin anda tukar :" << endl;
        int count=1;
        int idx;
        for (auto &t : state->playerTurn) {
            cout << count << ". p" << t.getId() << endl;
            count ++;
        }
        cin >> idx;
        vector<Card> temp=state->playerTurn.front().getCards();
        state->playerTurn.front().setCards(state->playerTurn[idx-1].getCards());
        state->playerTurn[idx-1].setCards(temp);
        this->used = true;
    }
}