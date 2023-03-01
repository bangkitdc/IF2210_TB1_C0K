#include "game.hpp"
#include <vector>
using namespace std;

vector<string> listCommand = {
    "NEXT",
    "RE-ROLL",
    "DOUBLE",
    "QUADRUPLE",
    "HALF",
    "QUARTER",
    "REVERSE",
    "SWAPCARD",
    "SWITCH",
    "ABILITYLESS",
    "HELP",
    "QUIT"
};

Game::Game() {
    this->round = 1;
    this->gameEnd = false;
}

void Game::startGame() {
    cout << "WELCOME TO POKER KW" << endl << endl;

    // inisiasi player, dll
    
    while (!gameEnd) {
        if (this->round == 1) {
            // inisiasi awal deck, tablecard, playercard, dll
            // kalau round 1 ditanya deck nya mau random apa dari file

        }

        try {
            string command = reqCommand();
        } catch (BaseException *e) {
            // exception
        }
    }
}

string Game::reqCommand() {
    string command;
    while(!this->gameEnd) {
        cout << "Massukan command:" << endl;
        cout << "> ";
        cin >> command;
        
        for (string com : listCommand) {
            if (com == command) {
                return command;
            }
        }

        // throw exception
        // throw new Invalid
    }

    return;
}

void Game::process(string) {

}

void Game::nextRound() {
    if (this->round == 6) {
        this->round = 1;
    } else {
        this->round += 1;
    }
}
