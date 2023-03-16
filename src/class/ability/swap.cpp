#include "swap.hpp"

Swap::Swap() : Ability("SWAP") {}

void Swap::use(string power, GameManager* state) {
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
        cout << "<p" << state->playerTurn.front().getId() << "> - ";
        cout << state->playerTurn.front().getName() << " melakukan SWAP\n";
        cout << "Silahkan pilih pemain yang kartunya ingin anda tukar :\n";
        cout << "   no - <id> - name\n";
        for (int i=1; i<7; i++) {
            cout << "   " << i << ". - " << "<p" << state->playerTurn.at(i).getId() << ">";
            cout << " - " << state->playerTurn.at(i).getName() << endl;
        }

        string id1, id2;
        while (true) {
            try {
                cout << "> ";
                cin >> id1;

                if (!isInteger(id1)) {
                throw NotNumberException(id1);
                }
                
                if (!(stoi(id1) >= 1 && stoi(id1) <= 6)) {
                    throw InvalidNumberException(id1);
                }

                break;
                
            } catch(InvalidNumberException& e) {
                cout << e.what() << endl;
            } catch(NotNumberException& e) {
                cout << e.what() << endl;
            }
        }

        cout << "Silahkan pilih pemain lain yang kartunya ingin anda tukar :\n";
        while (true) {
            try {
                cout << "> ";
                cin >> id2;

                if (!isInteger(id2)) {
                throw NotNumberException(id2);
                }
                
                if (!(stoi(id2) >= 1 && stoi(id2) <= 6)) {
                    throw InvalidNumberException(id2);
                }

                if (id1 == id2) {
                    throw SameNumberException();
                }

                break;
                
            } catch(InvalidNumberException& e) {
                cout << e.what() << endl;
            } catch(NotNumberException& e) {
                cout << e.what() << endl;
            } catch(SameNumberException& e) {
                cout << e.what() << endl;
            }
        }

        string p1, p2;

        cout << "Silahkan pilih kartu Kanan/Kiri <p" << state->playerTurn.at(stoi(id1)).getId() << "> - ";
        cout << state->playerTurn.at(stoi(id1)).getName() << " : \n    1. Kiri\n    2. Kanan\n";        
        while (true) {
            try {
                cout << "> ";
                cin >> p1;

                if (!isInteger(p1)) {
                throw NotNumberException(p1);
                }
                
                if (!(stoi(p1) >= 1 && stoi(p1) <= 2)) {
                    throw InvalidNumberException(p1);
                }

                break;
                
            } catch(InvalidNumberException& e) {
                cout << e.what() << endl;
            } catch(NotNumberException& e) {
                cout << e.what() << endl;
            }
        }

        cout << "Silahkan pilih kartu Kanan/Kiri <p" << state->playerTurn.at(stoi(id2)).getId() << "> - ";
        cout << state->playerTurn.at(stoi(id2)).getName() << " : \n    1. Kiri\n    2. Kanan\n";        
        while (true) {
            try {
                cout << "> ";
                cin >> p2;

                if (!isInteger(p2)) {
                throw NotNumberException(p2);
                }
                
                if (!(stoi(p2) >= 1 && stoi(p2) <= 2)) {
                    throw InvalidNumberException(p2);
                }

                break;
                
            } catch(InvalidNumberException& e) {
                cout << e.what() << endl;
            } catch(NotNumberException& e) {
                cout << e.what() << endl;
            }
        }
        int x1 = stoi(p1)-1, x2 = stoi(p2)-1;
        Card temp1 = state->playerTurn.at(stoi(id1)).getCards().at(x1);
        Card temp2 = state->playerTurn.at(stoi(id1)).getCards().at((x1+1)%2);
        Card temp3 = state->playerTurn.at(stoi(id2)).getCards().at(x2);
        Card temp4 = state->playerTurn.at(stoi(id2)).getCards().at((x2+1)%2);

        vector<Card> c1, c2;

        if (x1%2==0) {
            c1 = {temp3, temp2};
        }
        else {
            c1 = {temp2, temp3};
        }
        
        if (x2%2==0) {
            c2 = {temp1, temp4};
        }
        else {
            c2 = {temp4, temp1};
        }
        
        state->playerTurn.at(stoi(id1)).setCards(c1);
        state->playerTurn.at(stoi(id2)).setCards(c2);

        cout << "Berhasil menukar kartu!\n";
        
        this->used = true;
    }
}