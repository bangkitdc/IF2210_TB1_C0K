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
};

#endif