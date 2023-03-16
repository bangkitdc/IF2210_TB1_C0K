#include "reverse.hpp"

Reverse::Reverse() : Ability("REVERSE") {}

void Reverse::use(string power, GameManager* state) {
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
        this->used = true;

        cout << endl << state->getFirstPlayer().getName() << " melakukan REVERSE!\n";
        Player p1 = state->dequeuePlayer();
        Player p2 = state->dequeuePlayer();
        Player p3 = state->dequeuePlayer();
        Player p4 = state->dequeuePlayer();
        Player p5 = state->dequeuePlayer();
        Player p6 = state->dequeuePlayer();
        Player p7 = state->dequeuePlayer();
        state->enqueuePlayer(p1);
        state->enqueuePlayer(p7);
        state->enqueuePlayer(p6);
        state->enqueuePlayer(p5);
        state->enqueuePlayer(p4);
        state->enqueuePlayer(p3);
        state->enqueuePlayer(p2);
        
        cout << "\n(sisa) urutan eksekusi giliran ini : ";
        for (int i=state->turn; i<7; i++) {
            cout << "<p" << state->playerTurn.at(i).getId() << "> ";
        }
        cout << "\nurutan eksekusi ronde selanjutnya : ";
        for (int i=1; i<7; i++) {
            cout << "<p" << state->playerTurn.at(i).getId() << "> ";
        }
        cout << "<p" << state->playerTurn.at(0).getId() << ">\n";

        cout << "Silahkan lakukan perintah selanjutnya.\n";
        state->process(state->reqCommand());
        for (int i=1; i<state->turn; i++) {
            Player temp = state->dequeuePlayer();
            state->enqueuePlayer(temp);
        }       
    }
}