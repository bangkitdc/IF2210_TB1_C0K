#include "switch.hpp"

Switch::Switch() : Ability("SWITCH") {}

void Switch::use(string power, GameManager* state) {
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
        cout << state->playerTurn.front().getName() << " melakukan SWITCH\n";
        cout << "Silahkan pilih pemain yang kartunya ingin anda tukar :\n";
        cout << "   no - <id> - name\n";
        for (int i=1; i<7; i++) {
            cout << "   " << i << ". - " << "<p" << state->playerTurn.at(i).getId() << ">";
            cout << " - " << state->playerTurn.at(i).getName() << endl;
        }

        string id;
        while (true) {
            try {
                cout << "> ";
                cin >> id;

                if (!isInteger(id)) {
                throw NotNumberException(id);
                }
                
                if (!(stoi(id) >= 1 && stoi(id) <= 6)) {
                    throw InvalidNumberException(id);
                }

                break;
                
            } catch(InvalidNumberException& e) {
                cout << e.what() << endl;
            } catch(NotNumberException& e) {
                cout << e.what() << endl;
            }
        }

        vector<Card> temp = state->playerTurn.at(stoi(id)).getCards();
        state->playerTurn.at(stoi(id)).setCards(state->getFirstPlayer().getCards());
        state->playerTurn.at(0).setCards(temp);

        cout << "Kedua kartu <p" << state->playerTurn.front().getId() << "> - ";
        cout << state->playerTurn.front().getName() << " telah ditukar dengan ";
        cout << "<p" << state->playerTurn.at(stoi(id)).getId() << "> - ";
        cout << state->playerTurn.front().getName() << ".\n"; 


        cout << "Kartumu sekarang adalah :\n";
        state->getFirstPlayer().displayPlayerCard(0);
        cout << " && ";
        state->getFirstPlayer().displayPlayerCard(1);
        cout << endl;
        state->displayCardUI(state->getFirstPlayer().getCards(), 4);
        cout << endl;

        
        this->used = true;
    }
}