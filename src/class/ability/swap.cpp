#include "swap.hpp"

#include "../game/gameManager.hpp"

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
        cout << "dipake ya sayang\n";
        cout << "p" << state->playerTurn.front().getId() << "melakukan SWAPCARD" << endl;
        cout << "Kartumu sekarang adalah :\n";
        state->playerTurn.front().displayPlayerCard(0);
        cout << " && ";
        state->playerTurn.front().displayPlayerCard(1);
        cout << endl;
        cout << "Silahkan pilih pemain yang kartunya ingin anda tukar :" << endl;
        int count=1;
        int idx;
        int idxCardPlayer,idxCardPlayer2;
        for (auto &t : state->playerTurn) {
            cout << count << ". p" << t.getId() << endl;
            count ++;
        }
        cin >> idx;
        if (idx > 7){
            throw "Pilihan tidak valid";
        }
        cout << "Silahkan pilih kartu kanan/kiri pemain_" << state->playerTurn.front().getId() << " :\n";
        cout << "1. Kanan\n";
        cout << "2. Kiri\n";
        cin >> idxCardPlayer;
        if(idxCardPlayer==2){
            idxCardPlayer=0;
        }
        cout << "Silahkan pilih kartu kanan/kiri pemain_" << state->playerTurn[idx-1].getId() << " :\n";
        cout << "1. Kanan\n";
        cout << "2. Kiri\n";
        cin >> idxCardPlayer2;

        Card temp;
        Card temp2;

        if(idxCardPlayer2==2){
            idxCardPlayer2  =0;
        }
        if(idxCardPlayer==0){
            temp=state->playerTurn.front().getPlayerCard(0);
        }else{
            temp=state->playerTurn.front().getPlayerCard(1);
        }

        if(idxCardPlayer==0){
            temp2=state->playerTurn[idx-1].getPlayerCard(0);
        }else{
            temp2=state->playerTurn[idx-1].getPlayerCard(1);
        }

        if(idxCardPlayer==0){
            state->playerTurn.front().setCardDepan(temp2);
        }else{
            state->playerTurn.front().setCardBelakang(temp2);
        }

        if(idxCardPlayer2==0){
            state->playerTurn.front().setCardDepan(temp);
        }else{
            state->playerTurn.front().setCardBelakang(temp);
        }

        
        
        this->used = true;
    }
}