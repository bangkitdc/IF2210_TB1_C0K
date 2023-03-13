#include "gameManager.hpp"
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

GameManager::GameManager() : Game() {}

void GameManager::startGame() {
    cout << "Welcome to Poker KW" << endl << endl;

    // Initiate Main Deck Card
    DeckCard d;
    // DeckAbility da;
    DeckAbility* da = new DeckAbility();
    d.shuffleCard();

    // Input Player
    inputPlayer(d);
    printQueue();

    // sementara langsung gw bagiin ability dl
    // da->shuffleAbility(this);
    // problem disini

    while (!gameEnd) {
        if (round == 1) {
            // inisiasi awal deck, tablecard, playercard, dll
            // kalau round 1 ditanya deck nya mau random apa dari file

            setPrize(64);
        }

        if (round == 6) {
            // evaluate
        }

        cout << "prize: " << getPrize() << endl; 

        string command = reqCommand();
        process(command);

        // Next Turn
        Player temp = dequeuePlayer();
        // cout << temp.getAbility()->getPower() << "\n";
        enqueuePlayer(temp);

        printQueue();
        nextRound();
    }
}

void GameManager::inputPlayer(DeckCard &d) {
    cout << "Jumlah player pada game : 7" << endl;
    cout << "Silahkan masukkan username tiap player!!" << endl;

    do {
        string username;
        cout << "Masukkan username [P" << this->playerTurn.size() + 1 << "]: " << endl;
        cin >> username;

        Player temp(username, &d);
        this->enqueuePlayer(temp);
    } while (this->playerTurn.size() != 7);
}

string GameManager::reqCommand() {
    string command;
    while(!this->gameEnd) {
        try {
            cout << "Masukkan command:" << endl;
            cout << "> ";
            cin >> command;
            
            for (string com : listCommand) {
                if (com == command) {
                    return command;
                }
            }

            throw InvalidCommandException(command);
        } catch(InvalidCommandException& e) {
            cout << e.what() << endl;
        }
    }
    return "GAME END";
}

void GameManager::process(string command) {
    try {
        if (command == "NEXT") {
            cout << "Giliran dilanjut ke pemain berikutnya" << endl;

            if (true) {
                // throw exception
            }
        } else if (command == "RE-ROLL") {
            if (true) { // ga punya kartu
                throw NoCardException(command);
            } else { // punya kartu
                cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;

                // REROLL ALGORITHM

                cout << "Kamu mendapatkan 2 kartu baru yaitu:" << endl;

                // PRINT KARTU AJA
            }
        } else if (command == "DOUBLE") {
            int temp = getPrize();
            setPrize(temp * 2);

            cout << playerTurn.front().getName() << " melakukan DOUBLE! Poin hadiah naik dari" << endl;
            cout << temp << " menjadi " << getPrize() << "!" << endl;

            if (true) {
                // throw exception
            }
        } else if (command == "QUADRUPLE") {
            cout << "PPP\n";
            playerTurn.front().getAbility()->use(command, this);
            // if (true) { // ga punya kartu
            //     throw NoCardException(command);
            // } else { // punya kartu
            //     int temp = getPrize();
            //     setPrize(temp * 4);

            //     cout << playerTurn.front().getName() << " melakukan DOUBLE! Poin hadiah naik dari" << endl;
            //     cout << temp << " menjadi " << getPrize() << "!" << endl;

            //     // KURANGIN KARTU
            // }
        } else if (command == "HALF") {
            int temp = getPrize();
            if (temp != 1) {
                setPrize(temp / 2);

                cout << playerTurn.front().getName() << " melakukan HALF! Poin hadiah turun dari" << endl;
                cout << temp << " menjadi " << getPrize() << "!" << endl;
            } else {
                cout << playerTurn.front().getName() << " melakukan HALF! Sayangnya poin hadiah sudah bernilai" << endl;
                cout << temp << ". Poin hadiah tidak berubah.. Giliran dilanjut!" << endl;
            }

            if (true) {
                // throw exception
            }
        } else if (command == "QUARTER") {
            if (true) { // ga punya kartu
                throw NoCardException(command);
            } else { // punya kartu
                int temp = getPrize();
                if (temp != 1) {
                    setPrize(temp / 2);

                    cout << playerTurn.front().getName() << " melakukan HALF! Poin hadiah turun dari" << endl;
                    cout << temp << " menjadi " << getPrize() << "!" << endl;
                } else {
                    cout << playerTurn.front().getName() << " melakukan HALF! Sayangnya poin hadiah sudah bernilai" << endl;
                    cout << temp << ". Poin hadiah tidak berubah.. Giliran dilanjut!" << endl;
                }

                // KURANGIN KARTU
            }
        } else if (command == "REVERSE") {

            if (true) {
                // throw exception
            }
        } else if (command == "SWAPCARD") {

            if (true) {
                // throw exception
            }
        } else if (command == "SWITCH") {

            if (true) {
                // throw exception
            }
        } else if (command == "ABILITYLESS") {

            if (true) {
                // throw exception
            }
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
            // print skor terakhir

            cout << "Terima kasih telah bermain :p" << endl;
        } else {
            throw InvalidCommandException(command);
        }
    } catch (InvalidCommandException &e) {
        cout << e.what() << endl;
    }
}

void GameManager::enqueuePlayer(Player player) {
    this->playerTurn.push_back(player);
}

Player GameManager::dequeuePlayer() {
    Player player = this->playerTurn.front();

    this->playerTurn.pop_front();
    return player;
}

void GameManager::printQueue() {
    int count = 0;
    cout << "<";
    for (auto &t : playerTurn) {
        cout << "p" << t.getId();

        if (count < playerTurn.size() - 1) {
            cout << ",";
        }

        count ++;
    }
    cout << ">" << endl;
}
