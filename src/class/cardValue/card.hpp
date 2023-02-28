#ifndef _CARD_HPP_
#define _CARD_HPP_

#include <iostream>
#include <string>
#include "cardValue.hpp"
using namespace std;

class Card : public CardValue {
    protected:
        int num;                    // 1-13
        string warna;               // Hijau, Biru, Kuning, Merah
    public:
        Card();                     // default ctor
        Card(int, string);          // user-defined ctor
        Card(const Card&);          // cctor
        virtual ~Card();            // virtual dtor

        int getNum() const;
        void setNum(int);
        string getWarna() const;
        void setWarna(string);
        void displayCard();
        bool isValidCard() const;
        double getValue() const;
};

#endif