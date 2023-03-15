#ifndef _COMBINATION_HPP_
#define _COMBINATION_HPP_

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include "cardValue.hpp"
#include "../inventoryHolder/player.hpp"
#include <bits/stdc++.h>

using namespace std;

class Combination : public CardValue {
    public:
        Combination();
        ~Combination();

        void sortingWarna(vector<Card> &);
        void sortVector(vector<vector<Card>> &, vector<double> &);
        void sortCard(vector<Card>&);
        
        bool hasPair(vector<Card>);
        bool hasTwoPair(vector<Card>);
        bool hasThreeOfAKind(vector<Card>);
        bool hasStraight(vector<Card>);
        bool hasFlush(vector<Card>);
        bool hasFullHouse(vector<Card>);
        bool hasFourOfAKind(vector<Card>);
        bool hasStraightFlush(vector<Card>);

        ::pair<vector<vector<Card>>, vector<double>> highCard(vector<Card>);
        ::pair<vector<vector<Card>>, vector<double>> Pair(vector<Card>);
        ::pair<vector<vector<Card>>, vector<double>>twoPair(vector<Card>);
        ::pair<vector<vector<Card>>, vector<double>>threeOfAKind(vector<Card>);
        ::pair<vector<vector<Card>>, vector<double>> straight(vector<Card>);
        ::pair<vector<vector<Card>>, vector<double>> flush(vector<Card>);
        ::pair<vector<vector<Card>>, vector<double>> fullHouse(vector<Card>);
        ::pair<vector<vector<Card>>, vector<double>>  fourOfAKind(vector<Card>);
        ::pair<vector<vector<Card>>, vector<double>> straightFlush(vector<Card>);
        double priorityCard(vector<Card>);
        // pair<vector<vector<Card>>, int> highestOnTable(vector<Card>);
        // Player evaluate(vector<Card>);
        void eraseFirst(vector<vector<Card>>&);
        ::pair<vector<vector<Card>>, vector<double>> concatCombi(vector<Card>);

        Player evaluate(vector<Player>, vector<Card>);
        Player evaluateAgain(vector<Player>, vector<Card>, double);

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
