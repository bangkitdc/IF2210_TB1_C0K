#ifndef _COMBINATION_HPP_
#define _COMBINATION_HPP_

#include <vector>
#include <iostream>
#include <cmath>
#include "cardValue.hpp"
#include "../inventoryHolder/player.hpp"
using namespace std;

class Combination : public CardValue {
    public:
        Combination();
        ~Combination();

        void sortingWarna(vector<Card> &card);
        void sortVector(vector<vector<Card>> &result, vector<double> &val);
        void sortCard(vector<Card>&);
        
        bool hasPair(vector<Card> card);
        bool hasTwoPair(vector<Card> card);
        bool hasThreeOfAKind(vector<Card> card);
        bool hasStraight(vector<Card> card);
        bool hasFlush(vector<Card> card);
        bool hasFullHouse(vector<Card> card);
        bool hasFourOfAKind(vector<Card> card);
        bool hasStraightFlush(vector<Card> card);

        pair<vector<vector<Card>>, vector<double>> highCard(vector<Card> card);
        pair<vector<vector<Card>>, vector<double>> Pair(vector<Card>);
        pair<vector<vector<Card>>, vector<double>> twoPair(vector<Card>);
        pair<vector<vector<Card>>, vector<double>> threeOfAKind(vector<Card>);
        pair<vector<vector<Card>>, vector<double>> straight(vector<Card>);
        pair<vector<vector<Card>>, vector<double>> flush(vector<Card>);
        pair<vector<vector<Card>>, vector<double>> fullHouse(vector<Card>);
        pair<vector<vector<Card>>, vector<double>> fourOfAKind(vector<Card>);
        pair<vector<vector<Card>>, vector<double>> straightFlush(vector<Card>);
        double priorityCard(vector<Card> cards);
        // pair<vector<vector<Card>>, int> highestOnTable(vector<Card>);
        // Player evaluate(vector<Card>);
        void eraseFirst(vector<vector<Card>> &card);
        pair<vector<vector<Card>>, vector<double>> concatCombi(vector<Card>card);

        Player evaluateAgain(vector<Player> players, vector<Card> t, double m);

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
