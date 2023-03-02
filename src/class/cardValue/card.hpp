#ifndef _CARD_HPP_
#define _CARD_HPP_

#include <iostream>
#include <string>
#include "cardValue.hpp"
#include <utility>
using namespace std;

class Card {
    protected:
        // int num;                    // 1-13
        // string warna;               // Hijau, Biru, Kuning, Merah
        pair<int,string> card;
    public:
        // friend class Player;
        // friend class DeckCard;
        Card();                     // default ctor
        Card(int, string);          // user-defined ctor
        Card(const Card&);          // cctor
        virtual ~Card();            // virtual dtor

        int getNum() const;
        void setNum(int);
        string getWarna() const;
        void setWarna(string);

        bool isValidCard() const;
        double getValue() const;
        void displayCard();
};

#endif