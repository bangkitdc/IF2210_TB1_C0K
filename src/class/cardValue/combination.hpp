#ifndef _COMBINATION_HPP_
#define _COMBINATION_HPP_

#include <vector>
#include <iostream>
#include "cardValue.hpp"
#include "../inventoryHolder/player.hpp"
using namespace std;

class Combination : public CardValue {
    public:
        Combination();
        ~Combination();

        void sortingWarna(vector<Card> card);
        void sortCard(vector<Card>);
        
        bool hasPair(vector<Card> card);
        bool hasTwoPair(vector<Card> card);
        bool hasThreeOfAKind(vector<Card> card);
        bool hasStraight(vector<Card> card);
        bool hasFlush(vector<Card> card);
        bool hasFullHouse(vector<Card> card);
        bool hasFourOfAKind(vector<Card> card);
        bool hasStraightFlush(vector<Card> card);

        vector<Card> pair(vector<Card>);
        vector<Card> twoPair(vector<Card>);
        vector<Card> threeOfAKind(vector<Card>);
        vector<Card> straight(vector<Card>);
        vector<Card> flush(vector<Card>);
        vector<Card> fullHouse(vector<Card>);
        vector<Card> fourOfAKind(vector<Card>);
        vector<Card> straightFlush(vector<Card>);
        int priorityCard(vector<Card> cards);

        int color2Int(Card);

        double highVal(int angka, int warna);
        double pairVal(int angka, int warna1, int warna2);
        double twoPairVal(int angka1, int angka2, int warna1_a, int warna1_b, int warna2_a, int warna2_b);
        double threesVal(int angka, int warna1, int warna2, int warna3);
        double straightVal(int angkaTerkecil, int warna1, int warna2, int warna3, int warna4, int warna5);
        double flushVal(int angka1, int angka2, int angka3, int angka4, int angka5, int warna);
        double fullHouseVal(int angka1, int angka2, int warna1_1, int warna1_2, int warna1_3, int warna2_1, int warna2_2);
        double foursVal(int angka);
        double straightFlushVal(int angka1, int angka2, int angka3, int angka4, int angka5, int warna);
};

#endif