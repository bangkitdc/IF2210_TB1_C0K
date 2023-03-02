#include "deckCard.hpp"
#include "deckCard.cpp"
#include "inventoryHolder.cpp"
#include "../cardValue/card.cpp"
#include "../cardValue/combination.cpp"
#include <iostream>
#include "tableCard.hpp"
#include "tableCard.cpp"
#include "player.hpp"
#include "Player.cpp"


int main(){
    Combination c;
    vector<Card> cards;
    
    Card t(8,"Hijau");
    Card u(11,"Hijau");
    Card v(10,"Kuning");
    Card w(10,"Merah");
    Card x(8,"Biru");
    Card y(9,"Hijau");
    Card z(10,"Hijau");

    cards.push_back(t);
    cards.push_back(u);
    cards.push_back(v);
    cards.push_back(w);
    cards.push_back(x);
    cards.push_back(y);
    cards.push_back(z);

    for(int i = 0; i<7; i++){
        cout << cards[i].getNum() << cards[i].getWarna() << endl;
    }
    if(c.hasFlush(cards)){
        cout << "TEST" << endl;
        cards = c.flush(cards);
    }
    cout << "PEMBATAS" << cards.size() << endl;

    for(int i = 0; i < cards.size() ; i++){
        cout << cards[i].getNum() << cards[i].getWarna() << endl;
    }

}
