#ifndef _COMBINATION_HPP_
#define _COMBINATION_HPP_

#include <iostream>
#include "cardValue.hpp"
#include "../inventoryHolder/player.hpp"
using namespace std;

class Combination : public CardValue {
    protected:
        vector<Card> card;
    public:
        double getValue();

        bool hasPair();
        bool hasTwoPair();
        bool hasThreeOfAKind();
        bool hasStraight();
        bool hasFlush();
        bool hasFullHouse();
        bool hasFourOfAKind();
        bool hasStraightFlush();

        vector<Card> pair(vector<Card>);
        vector<Card> twoPair(vector<Card>);
        vector<Card> threeOfAKind(vector<Card>);
        vector<Card> straight(vector<Card>);
        vector<Card> flush(vector<Card>);
        vector<Card> fullHouse(vector<Card>);
        vector<Card> fourOfAKind(vector<Card>);
        vector<Card> straightFlush(vector<Card>);
};

#endif