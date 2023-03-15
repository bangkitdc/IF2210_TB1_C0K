#include "gameManager.hpp"
#include "../../utility/utility.hpp"
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
    do {
        gameReset();
        int inpGame = inputGame();

        if (inpGame == 1) {
            cout << "Welcome to Poker KW" << endl << endl;

            // Input Player
            inputPlayer(7);

            while (!gameEnd) {
                // Initiate Main Deck Card, Table Card
                
                this->d = DeckCard();
                this->d.shuffleCard();
                // this->d.displayDeckCard();
                tableCard t;

                DeckAbility *da = new DeckAbility();
                da->distributeAbility(this);
                

                while(!gameEnd) {
                    if (round == 7) {
                        // EVALUATE
                        Player temp = dequeuePlayer();
                        enqueuePlayer(temp);

                        // SEMENTARA PRIZE GW ASSIGN LANGSUNG KE P1
                        playerTurn.front().addPoint(prize);
                        cout << "\n\n";
                        printPrize(prize);
                        cout << " DIBERIKAN KE P1!\n\n"
                        cout << "====================================================="
                        cout << "\nPoint player:\n";
                        
                        printPlayersPoint();

                        if (getFirstPlayer().getPoint() >= pow(2,32)) {
                            cout << "\nP1 MENANG!!!!!!!!!!!\n\n";
                            gameEnd = true;
                            break;
                        } else {
                            cout << "\nPermainan diulang!\n";
                            this->d = DeckCard();
                            this->d.shuffleCard();
                            t = tableCard();
                            setPrize(64);
                            this->round = 1;
                            this->turn = 1;
                            da->resetAbilityDeck();
                            da->distributeAbility(this);
                        }
                    }
                    if (round == 1 && turn == 1) {
                        // inisiasi awal deck, tablecard, playercard, dll
                        // kalau round 1 ditanya deck nya mau random apa dari file
                        int pil = inputOpsi();

                        if (pil == -1) {
                            break;
                        }

                        if (pil == 2) {
                            string fileInput = inputFile();
                            if (fileInput == "nofile") {
                                cout << "Tidak terdapat file di dalam directory /test, Deck Card akan di-random" << endl;
                            } else {
                                try {
                                    d.readFromFile(fileInput);
                                } catch(fileInvalidException &e) {
                                    cout << RED << endl << e.what() << RESET << endl << endl;
                                    cout << "Deck Card akan di-random" << endl;
                                }
                            }
                        } else {
                            this->d.shuffleCard();
                        }

                        // Assign deck ke masing-masing player
                        for (auto &p : playerTurn) {
                            p.setCardN(d, 2);
                        }

                        setPrize(64);
                    }

                    if (round != 6 && turn == 1) {
                        t.addCard(d.getCard());
                    }

                    if (round == 2 && turn == 1) {
                        da->shuffleAbility(this);
                        da->distributeAbility(this);
                    }
                    
                    t.displayTCard();
                    cout << "\n=====================================================\n";
                    cout << "Round : " << round << "\n";
                    cout << "Turn  : " << turn << "\n";
                    cout << "Prize : ";
                    printPrize(prize);
                    cout << endl;
                    cout << "Queue : ";
                    printQueue();
                    cout << "Giliran saat ini: p" << getFirstPlayer().getId() << endl;
                    cout << "Player cards:\n";
                    playerTurn.front().displayPlayerCard(0);
                    cout << " & ";
                    playerTurn.front().displayPlayerCard(1);
                    cout << endl << endl;
                    if (round > 1) {
                        cout << "Kamu punya ability: " << getFirstPlayer().getAbility()->getPower() << endl;
                    }

                    string command = reqCommand();
                    process(command);

                    // Next Turn
                    Player temp = dequeuePlayer();
                    enqueuePlayer(temp);

                    nextTurn();
                }   

                CheckWin(playerTurn);
                delete da;
            }
        } else if (inpGame == 2) {
            cout << "Welcome to Cangkulan" << endl;
            
            DeckCard d;
            tableCard t;
            d.shuffleCard();

            // Input Player
            inputPlayer(4, d, 3);

            for (int i = 0; i < 4; i ++) {
                playerTurn[i].displayPlayer(false);
                cout << endl;
            }

            cout << "Urutan giliran: ";
            printQueue();

            while (!gameEnd) {
                bool flag = true;
                cout << endl << "Giliran saat ini: p" << getFirstPlayer().getId() << endl;

                if (t.isTCardEmpty()) {
                    cout << "Silahkan mengeluarkan kartu bebas!" << endl;
                    playerTurn[0].displayPlayerCards();

                    int x = inputCangkul(1, playerTurn[0].getCards().size());
                    if (x == -1) {

                       break;     
                    }

                    addPlayerCard(t, playerTurn[0], x - 1);
                } else {
                    t.displayTCard();
                    string warna = t.getFirstCard().getWarna();
                    vector<int> listIndex;
                    listIndex = countPlayerCardWithColor(playerTurn[0], warna);

                    if (listIndex.size() != 0) {
                        cout << "Berikut kartu yang dimiliki player dengan warna " << warna << "!" << endl;
                        displayPlayerCardWithColor(playerTurn[0], warna);

                        int x = inputCangkul(1, listIndex.size());
                        if (x == -1) {
                            break;
                        }

                        addPlayerCard(t, playerTurn[0], listIndex[x - 1]);
                    } else {
                        cout << "Pemain tidak memiliki kartu dengan warna " << warna << "!" << endl;
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
                }

                if(t.getCards().size() == 4) {
                    t.sortTableCard();

                    cout << endl << "Player dengan username " << playerTurn[0].getName() << " memiliki kartu paling besar, yaitu: ";
                    t.getCardWithoutPop(0).displayCard(); cout << endl;

                    evaluateQueue(t);

                    cout << endl << "Urutan giliran yang baru: ";

                    printQueue();

                    flag = false;
                    t.clearCards();
                    t.clearMilik();
                    CheckWin2(playerTurn);
                }

                if (flag) {
                    // Next Turn
                    Player temp = dequeuePlayer();
                    enqueuePlayer(temp);
                }
            }
        } else { // EXIT
            programEnd = true;
        }
    } while(!programEnd);

    cout << "Program selesai, sampai jumpa lagi" << endl;
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
            cout << RED << endl << e.what() << RESET << endl << endl;
        } catch(NotNumberException& e) {
            cout << RED << endl << e.what() << RESET << endl << endl;
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
            cout << "Ketik `-1` jika ingin keluar dari game" << endl << endl;
            cout << "1. Opsi Random" << endl;
            cout << "2. Opsi Baca File" << endl;
            cout << "Masukkan pilihan: " << endl;
            cout << "> ";
            cin >> i;

            if (!isInteger(i)) {
                throw NotNumberException(i);
            }

            if (stoi(i) == -1) {
                this->gameEnd = true;

                cout << endl << "Terima kasih telah bermain Poker KW :p" << endl;
                return -1;
            }
            
            if (!(stoi(i) >= 1 && stoi(i) <= 2)) {
                throw InvalidNumberException(i);
            }

            flag = false;
        } catch(InvalidNumberException& e) {
            cout << RED << endl << e.what() << RESET << endl << endl;
        } catch(NotNumberException& e) {
            cout << RED << endl << e.what() << RESET << endl << endl;
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
            cout << "3. Quit Game" << endl;
            cout << "Masukkan pilihan: " << endl;
            cout << "> ";
            cin >> i;

            if (!isInteger(i)) {
                throw NotNumberException(i);
            }
            
            if (!(stoi(i) >= 1 && stoi(i) <= 3)) {
                throw InvalidNumberException(i);
            }

            flag = false;
        } catch(InvalidNumberException& e) {
            cout << RED << endl << e.what() << RESET << endl << endl;
        } catch(NotNumberException& e) {
            cout << RED << endl << e.what() << RESET << endl << endl;
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
            cout << RED << endl << e.what() << RESET << endl << endl;
        }
    }
    return "GAME END";
}

void GameManager::process(string command) {
    try {
        if (command == "NEXT") {
            cout << "Giliran dilanjut ke pemain berikutnya" << endl;
        } else if (command == "DOUBLE") {
            __uint128_t temp = getPrize();
            setPrize(temp * 2);

            cout << playerTurn.front().getName() << " melakukan DOUBLE! Poin hadiah naik dari" << endl;
            printPrize(temp);
            cout << " menjadi ";
            printPrize(prize);
            cout << "!" << endl;

        } else if (command == "HALF") {
            __uint128_t temp = getPrize();
            if (temp != 1) {
                setPrize(temp / 2);

                cout << playerTurn.front().getName() << " melakukan HALF! Poin hadiah turun dari" << endl;
                printPrize(temp);
                cout << " menjadi ";
                printPrize(prize);
                cout << "!" << endl;
            } else {
                cout << playerTurn.front().getName() << " melakukan HALF! Sayangnya poin hadiah sudah bernilai 1. ";
                cout << "Poin hadiah tidak berubah.. Giliran dilanjut!" << endl;
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

            cout << endl << "Terima kasih telah bermain Poker KW :p" << endl;
        } else {
            try {
                getFirstPlayer().getAbility()->use(command, this);
            } catch (NoCardException &e) {
                cout << RED << endl << e.what() << RESET << endl << endl;
                process(reqCommand());
            } catch (UsedCardException &e) {
                cout << RED << endl << e.what() << RESET << endl << endl;
                process(reqCommand());
            } catch (NoAbilityException &e) {
                cout << RED << endl << e.what() << RESET << endl << endl;
                process(reqCommand());
            } catch (AbilityOffException &e) {
                cout << RED << endl << e.what() << RESET << endl << endl;
                process(reqCommand());
            }
            
        }
    } catch (InvalidCommandException &e) {
        cout << RED << endl << e.what() << RESET << endl << endl;
    }
}

void GameManager::printQueue() {
    for (auto &t : playerTurn) {
        cout << "<p" << t.getId() << "> ";
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

void GameManager::CheckWin(deque<Player> & p) {
    for (int i = 0; i < 7; i ++) {
        if (p[i].getPoint() >= pow(2, 32)) {
            cout << "Selamat!! Pemain dengan username " << p[i].getName() << " memenangkan permainan!" << endl;
            cout << "Pemain telah mencapai poin: ";
            printPrize(p[i].getPoint());
            cout << "\nPoin sudah melebihi " << pow(2,32) << endl;

            this->gameEnd = true;
        }
    }
}

/* BONUS */

int GameManager::inputCangkul(int a, int b) {
    string i;
    bool flag = true;
    while(flag) {
        try {
            if (a != b) {
                cout << "Silahkan pilih kartu yang ingin dikeluarkan: " << "(" << a << " - " << b << ")" << endl;
            } else {
                cout << "Silahkan pilih kartu yang ingin dikeluarkan: (1) pilihan saja" << endl;
            }
            cout << "Ketik `-1` jika ingin keluar dari game" << endl << endl;

            cout << "> ";
            cin >> i;

            if (!isInteger(i)) {
                throw NotNumberException(i);
            }

            if (stoi(i) == -1) {
                this->gameEnd = true;

                cout << endl << "Terima kasih telah bermain Poker KW :p" << endl;
                return -1;
            }
            
            if (!(stoi(i) >= a && stoi(i) <= b)) {
                throw InvalidNumberException(i);
            }

            flag = false;
        } catch(InvalidNumberException& e) {
            cout << RED << endl << e.what() << RESET << endl << endl;
        } catch(NotNumberException& e) {
            cout << RED << endl << e.what() << RESET << endl << endl;
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
            cout << endl;
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

void GameManager::evaluateQueue(tableCard &t) {
    int count = t.getCards().size();
    int i = 0;

    t.displayTCard();
    while (i < count) {
        int id = t.getMilik(i);
        int idx = findIdxWithId(id);
        Player temp = getPlayer(idx);

        enqueuePlayer(temp);
        i ++;
    }

    for (int j = 0; j < count; j ++) {
        playerTurn.pop_front();
    }
}

int GameManager::findIdxWithId(int id) {
    for (int i = 0; i < this->playerTurn.size(); i ++) {
        if (playerTurn[i].getId() == id) {
            return i;
        }
    }

    return -1;
}