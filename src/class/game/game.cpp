#include "game.hpp"
using namespace std;

const string listCommand[] = {
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
            process(command);
        } catch (BaseException *e) {
            // exception
        }
    }
}

string Game::reqCommand() {
    string command;
    while(!this->gameEnd) {
        cout << "Masukan command:" << endl;
        cout << "> ";
        cin >> command;
        
        for (string com : listCommand) {
            if (com == command) {
                return command;
            }
        }

        // throw exception
        throw new InvalidCommandException(command);
    }

    return "GAME END";
}

void Game::process(string command) {
    try {
        if (command == "NEXT") {

        } else if (command == "RE-ROLL") {

        } else if (command == "DOUBLE") {

        } else if (command == "QUADRUPLE") {

        } else if (command == "HALF") {

        } else if (command == "QUARTER") {

        } else if (command == "REVERSE") {

        } else if (command == "SWAPCARD") {

        } else if (command == "SWITCH") {

        } else if (command == "ABILITYLESS") {

        } else if (command == "HELP") {
            cout << endl << "Command yang tersedia: " << endl;
            cout << "NEXT \t: " << "Perintah untuk tidak melakukan apa-apa. Giliran dilanjutkan ke pemain berikutnya" << endl;
            cout << "RE-ROLL \t: " << "PreReq: Re-Roll Card. Perintah untuk membuang 2 kartu tangan pemanggil dan mengambil ulang 2 kartu baru dari deck" << endl;
            cout << "DOUBLE \t: " << "Perintah untuk menaikkan total poin hadiah menjadi 2x lipat" << endl;
            cout << "QUADRUPLE \t: " << "PreReq: Double Card. Perintah untuk menaikkan total poin hadiah menjadi 4x lipat" << endl;
            cout << "HALF \t: " << "Perintah untuk menurunkan total poin hadiah menjadi (1/2)x lipat" << endl;
            cout << "QUARTER \t: " << "Perintah untuk menurunkan total poin hadiah menjadi (1/4)x lipat" << endl;
            cout << "REVERSE \t: " << "Perintah untuk memutar arah giliran pemain" << endl;
            cout << "SWAPCARD \t: " << "Perintah untuk menukar 1 kartu pemain lain dengan 1 kartu pemain yang lain" << endl;
            cout << "SWITCH \t: " << "Perintah untuk menukar 2 kartu tangan pemanggil dengan 2 kartu tangan pemain lain" << endl;
            cout << "ABILITYLESS \t: " << "Perintah untuk mematikan kemampuan kartu lawan" << endl;
            cout << "HELP \t: " << "Perintah untuk menampilkan semua command yang tersedia" << endl;
            cout << "QUIT \t: " << "Perintah untuk keluar game" << endl;
        } else if (command == "QUIT") {
            this->gameEnd = true;
            // skor terakhir

            cout << "Terima kasih telah bermain :p" << endl;
        } else {
            throw new InvalidCommandException(command);
        }
    } catch (BaseException *e) {
        throw new FailedCommandException(e, command);
    }
}

Game& Game::operator<<(const Player& player) {
    this->playerTurn.push(player);

    return *this;
}

Game &operator>>(Game &game, Player &player) {
    player = game.playerTurn.front();
    game.playerTurn.pop();

    return game;
}

void Game::nextRound() {
    if (this->round == 6) {
        this->round = 1;
    } else {
        this->round += 1;
    }
}
