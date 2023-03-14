#include "reverse.hpp"
#include "../game/gameManager.hpp"
#include <algorithm>
#include <deque>

Reverse::Reverse() : Ability("REVERSE") {}

void Reverse::use(string power, GameManager* state) {
    if (this->power != power) {
        throw NoCardException(power);
    }
    else if (this->used) {
        throw UsedCardException(power);
    }
    else {
        this->used = true;

        cout << state->getFirstPlayer().getName() << " melakukan REVERSE!" << endl;
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
        state->process(state->reqCommand());
        for (int i=1; i<state->turn; i++) {
            Player temp = state->dequeuePlayer();
            state->enqueuePlayer(temp);
        }       
    }
}

/*
1
2
3 4 5 6 7 1 2
4

*/