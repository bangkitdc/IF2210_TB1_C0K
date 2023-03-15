#include "abilityless.hpp"

AbilityLess::AbilityLess() : Ability("ABILITYLESS") {}

void AbilityLess::use(string power, GameManager* state) {
    if (this->power != power) {
        throw NoCardException(power);
    }
    else if (this->used) {
        throw UsedCardException(power);
    }
    else {
        this->used = true;
        
        cout << endl;
        cout << state->getFirstPlayer().getName() << " akan mematikan kartu ablity lawan!\n";
        cout << "Silahkan pilih pemain yang kartu abilitynya ingin dimatikan:\n";
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

        int idd = stoi(id);
        if (state->playerTurn.at(stoi(id)).getAbility()->isUsed()) {
            cout << "Kartu ability <p" << state->playerTurn.at(stoi(id)).getId() << "> - ";
            cout << state->playerTurn.at(stoi(id)).getName() << " telah dipakai sebelumnya.";
            cout << "\nYah, sayang penggunaan kartu ini sia-sia :(.\n";
        } else {
            state->playerTurn.at(stoi(id)).getAbility()->setActive(false);
            cout << "Kartu ability <p" << state->playerTurn.at(stoi(id)).getId() << "> - ";
            cout << state->playerTurn.at(stoi(id)).getName() << " telah dimatikan.\n";
        }
    }
}