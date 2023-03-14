#include "gameManager.hpp"
#include <filesystem>
#include <iostream>
#include <vector>
#include <string>

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
    "SWAP",
    "ABILITYLESS",
    "HELP",
    "QUIT"
};

GameManager::GameManager() : Game() {}

void GameManager::startGame() {
    int inpGame = inputGame();

    if (inpGame == 1) {
        cout << "Welcome to Poker KW" << endl << endl;

        // Input Player
        inputPlayer(7);
        printQueue();

        while (!gameEnd) {
            // Initiate Main Deck Card, Table Card
            DeckCard d;
            tableCard t;

            // DeckAbility da;
            DeckAbility *da = new DeckAbility();
            da->distributeAbility(this);
            // da->shuffleAbility(this);
            // da->distributeAbility(this);
            

            d.shuffleCard();

            while(round != 6 && !gameEnd) {
                if (round == 1 && turn == 1) {
                    // inisiasi awal deck, tablecard, playercard, dll
                    // kalau round 1 ditanya deck nya mau random apa dari file
                    int pil = inputOpsi();
                    if (pil == 2) {
                        string fileInput = inputFile();
                        d.readFromFile(fileInput);
                    } else {
                        for (auto &p : playerTurn) {
                            p.setCardN(d, 2);
                        }
                    }

                    setPrize(64);
                }

                if (round == 2 && turn == 1) {
                    da->shuffleAbility(this);
                    da->distributeAbility(this);
                }

                if (round == 6) {
                    // evaluate
                    // Combination c;

                    // Player p1;
                    // p1 = c.evaluate(getPlayers())

                }

                cout << endl << "Prize saat ini: " << getPrize() << endl; 
                cout << endl << "Giliran saat ini: p" << getFirstPlayer().getId() << endl;
                cout << "Player cards: ";
                playerTurn[0].displayPlayerCards();
                cout << endl;
                cout << "Round: " << round << "\n";
                cout << "Turn " << turn << "\n";
                if (round > 1) {
                    cout << "Kamu punya ability: " << getFirstPlayer().getAbility()->getPower() << endl;
                }

                string command = reqCommand();
                process(command);

                // Next Turn
                Player temp = dequeuePlayer();
                enqueuePlayer(temp);

                nextTurn();
                printQueue();
            }            
        }
    } else {
        cout << "Welcome to Cangkulan" << endl << endl;
        
        DeckCard d;
        tableCard t;
        d.shuffleCard();

        // Input Player
        inputPlayer(4, d, 3);
        printQueue();

        for (int i = 0; i < 4; i ++) {
            playerTurn[i].displayPlayer();
        }

        while (!gameEnd) {
            bool flag = true;
            cout << endl << "Giliran saat ini: p" << getFirstPlayer().getId() << endl;

            if (t.isTCardEmpty()) {
                cout << "Silahkan mengeluarkan kartu bebas!" << endl;
                playerTurn[0].displayPlayerCards();

                int x = inputCangkul(1, playerTurn[0].getCards().size());

                addPlayerCard(t, playerTurn[0], x - 1);

                CheckWin2(playerTurn);
            } else {
                t.displayTCard();
                string warna = t.getFirstCard().getWarna();
                vector<int> listIndex;
                listIndex = countPlayerCardWithColor(playerTurn[0], warna);

                if (listIndex.size() != 0) {
                    cout << "Berikut kartu yang dimiliki player dengan warna " << warna << "!" << endl;
                    displayPlayerCardWithColor(playerTurn[0], warna);

                    int x = inputCangkul(1, listIndex.size());

                    addPlayerCard(t, playerTurn[0], listIndex[x - 1]);
                } else {
                    cout << "Pemain tidak memiliki kartu dengan warna" << warna << "!" << endl;
                    cout << "Silahkan mengambil kartu di cangkulan sampe dapet, hehe" << endl;

                    bool dapet = false;
                    while (!d.isDeckEmpty() && !dapet) {
                        Card temp = d.getTopCard();
                        cout << "Player mendapat kartu "; temp.displayCard();

                        playerTurn[0].addCardFromDeck(d); // sekalian dipop dari deck
                        if (temp.getWarna() == warna) {
                            dapet = true;
                            cout << "Player mendapat kartu dengan warna yang sama dengan table" << endl;
                        } else {
                            cout << "Player mendapat kartu dengan warna berbeda dengan table, silahkan cangkul lagi :D" << endl;
                        }
                    }

                    if (!dapet && d.isDeckEmpty()) {
                        moveAllTableCardToPlayer(playerTurn[0], t);
                        cout << "Cangkulan habis, silahkan ambil kartu di table, xixixixi" << endl;
                    }
                    flag = false;
                }
                CheckWin2(playerTurn);
            }

            if(t.getCards().size() == 4) {
                int idKalah = evaluate(t);
                int idxKartuDiTable = evaluateIdxTable(t);

                // evaluate
                int idxKalah = findIdxWithId(idKalah);
                cout << "Player dengan username " << playerTurn[idxKalah].getName() << " memiliki kartu paling kecil, yaitu ";
                t.getCardWithoutPop(idxKartuDiTable).displayCard();
                cout << "Dia harus mengambil semua kartu yang ada di meja :p" << endl;

                if (idxKalah != -1) {
                    moveAllTableCardToPlayer(playerTurn[idxKalah], t);
                }
            }

            if (flag) {
                // Next Turn
                Player temp = dequeuePlayer();
                enqueuePlayer(temp);
            }
        }
    }
}

void GameManager::inputPlayer(int x) {
    cout << "Jumlah player pada game : " << x << endl;
    cout << "Silahkan masukkan username tiap player!!" << endl;

    do {
        string username;
        cout << "Masukkan username [P" << this->playerTurn.size() + 1 << "]: " << endl;
        cin >> username;

        Player temp(username);
        this->enqueuePlayer(temp);
    } while (this->playerTurn.size() != x);
}

void GameManager::inputPlayer(int x, DeckCard& d, int n) {
    cout << "Jumlah player pada game : " << x << endl;
    cout << "Silahkan masukkan username tiap player!!" << endl;

    do {
        string username;
        cout << "Masukkan username [P" << this->playerTurn.size() + 1 << "]: " << endl;
        cin >> username;

        Player temp(username, d, n);
        this->enqueuePlayer(temp);
    } while (this->playerTurn.size() != x);
}

string GameManager::inputFile() {
    // Path to the directory
    string path_string = "test";

    filesystem::path path(path_string);

    cout << "Files in directory " << path.filename() << ":" << endl;

    vector<string> s;

    int count = 0;
    for (const auto &entry : filesystem::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            count++;
            cout << count << ". " << entry.path().filename() << endl;

            s.push_back(entry.path().filename().string());
        }
    }

    if (count == 0) {
        return "nofile";
    }

    string i;
    bool flag = true;
    while(flag) {
        try {
            cout << "Masukkan nomor file:" << endl;
            cout << "> ";
            cin >> i;

            if (!isInteger(i)) {
                throw NotNumberException(i);
            }
            
            if (!(stoi(i) >= 1 && stoi(i) <= count)) {
                throw InvalidNumberException(i);
            }

            flag = false;
        } catch(InvalidNumberException& e) {
            cout << e.what() << endl;
        } catch(NotNumberException& e) {
            cout << e.what() << endl;
        }
    }

    return s[stoi(i) - 1];
}

int GameManager::inputOpsi() {
    string i;
    bool flag = true;
    while(flag) {
        try {
            cout << "Untuk urutan Deck Card, terdapat 2 Opsi" << endl;
            cout << "1. Opsi Random" << endl;
            cout << "2. Opsi Baca File" << endl;
            cout << "Masukkan pilihan: " << endl;
            cout << "> ";
            cin >> i;

            if (!isInteger(i)) {
                throw NotNumberException(i);
            }
            
            if (!(stoi(i) >= 1 && stoi(i) <= 2)) {
                throw InvalidNumberException(i);
            }

            flag = false;
        } catch(InvalidNumberException& e) {
            cout << e.what() << endl;
        } catch(NotNumberException& e) {
            cout << e.what() << endl;
        }
    }

    return stoi(i);
}

int GameManager::inputGame() {
    string i;
    bool flag = true;
    while(flag) {
        try {
            cout << "Terdapat 2 Permainan" << endl;
            cout << "1. Poker KW" << endl;
            cout << "2. Cangkulan" << endl;
            cout << "Masukkan pilihan: " << endl;
            cout << "> ";
            cin >> i;

            if (!isInteger(i)) {
                throw NotNumberException(i);
            }
            
            if (!(stoi(i) >= 1 && stoi(i) <= 2)) {
                throw InvalidNumberException(i);
            }

            flag = false;
        } catch(InvalidNumberException& e) {
            cout << e.what() << endl;
        } catch(NotNumberException& e) {
            cout << e.what() << endl;
        }
    }

    return stoi(i);
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
        
        } else if (command == "DOUBLE") {
            int temp = getPrize();
            setPrize(temp * 2);

            cout << playerTurn.front().getName() << " melakukan DOUBLE! Poin hadiah naik dari" << endl;
            cout << temp << " menjadi " << getPrize() << "!" << endl;

            if (true) {
                // throw exception
            }
        } else if (command == "HALF") {
            int temp = getPrize();
            if (temp != 1) {
                setPrize(temp / 2);

                cout << playerTurn.front().getName() << " melakukan HALF! Poin hadiah turun dari" << endl;
                cout << temp << " menjadi " << getPrize() << "!" << endl;
            } else {
                cout << playerTurn.front().getName() << " melakukan HALF! Sayangnya poin hadiah sudah bernilai";
                cout << temp << ". Poin hadiah tidak berubah.. Giliran dilanjut!" << endl;
            }

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
            try {
                getFirstPlayer().getAbility()->use(command, this);
            } catch (NoCardException &e) {
                cout << e.what() << endl;
                process(reqCommand());
            } catch (UsedCardException &e) {
                cout << e.what() << endl;
                process(reqCommand());
            } catch (NoAbilityException &e) {
                cout << e.what() << endl;
                process(reqCommand());
            }
            
        }
    } catch (InvalidCommandException &e) {
        cout << e.what() << endl;
        // process(reqCommand());
    }
}

void GameManager::printQueue() {
    int count = 0;
    for (auto &t : playerTurn) {
        cout << "<p" << t.getId() << "> ";
        count ++;
    }
    cout << endl;
}

bool GameManager::isInteger(const string& str) {
    try {
        stoi(str);
        return true;
    }
    catch (const exception&) {
        return false;
    }
}

/* BONUS */

int GameManager::inputCangkul(int a, int b) {
    string i;
    bool flag = true;
    while(flag) {
        try {
            cout << "Silahkan pilih kartu yang ingin dikeluarkan: " << "(" << a << " - " << b << ")" << endl;
            cout << "> ";
            cin >> i;

            if (!isInteger(i)) {
                throw NotNumberException(i);
            }
            
            if (!(stoi(i) >= a && stoi(i) <= b)) {
                throw InvalidNumberException(i);
            }

            flag = false;
        } catch(InvalidNumberException& e) {
            cout << e.what() << endl;
        } catch(NotNumberException& e) {
            cout << e.what() << endl;
        }
    }

    return stoi(i);
}

void GameManager::CheckWin2(deque<Player> & p) {
    for (int i = 0; i < 4; i ++) {
        if (p[i].getCards().size() == 0) {
            cout << "Selamat!! Pemain dengan username " << p[i].getName() << " memenangkan permainan!" << endl;
            cout << "Pemain telah dahulu menghabiskan kartu dan game telah selesai ><" << endl;

            this->gameEnd = true;
        }
    }
}

void GameManager::displayPlayerCardWithColor(Player &p, string warna) {
    int count = 0;

    for (int i = 0; i < p.getCards().size(); i ++) {
        if (p.getPlayerCardWithoutPop(i).getWarna() == warna) {
            count ++;
            cout << count << ". ";
            p.getPlayerCardWithoutPop(i).displayCard();
        }
    }
}

vector<int> GameManager::countPlayerCardWithColor(Player &p, string warna) {
    vector<int> temp;
    for (int i = 0; i < p.getCards().size(); i ++) {
        if (p.getPlayerCardWithoutPop(i).getWarna() == warna) {
            temp.push_back(i);
        }
    }
    return temp;
}

int GameManager::evaluate(tableCard &t) {
    int min = t.getCardWithoutPop(0).getNum();
    int id = t.getMilik(0);

    for (int i = 1; i < t.getCards().size(); i ++) {
        if (t.getCardWithoutPop(i).getNum() < min) {
            min = t.getCardWithoutPop(i).getNum();
            id = t.getMilik(i);
        }
    }

    return id;
}

int GameManager::evaluateIdxTable(tableCard &t) {
    int min = t.getCardWithoutPop(0).getNum();
    int idx = 0;

    for (int i = 1; i < t.getCards().size(); i ++) {
        if (t.getCardWithoutPop(i).getNum() < min) {
            min = t.getCardWithoutPop(i).getNum();
            idx = i;
        }
    }

    return idx;
}

int GameManager::findIdxWithId(int idKalah) {
    for (int i = 0; i < this->playerTurn.size(); i ++) {
        if (playerTurn[i].getId() == idKalah) {
            return i;
        }
    }

    return -1;
}