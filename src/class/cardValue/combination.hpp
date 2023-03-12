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
};

#endif