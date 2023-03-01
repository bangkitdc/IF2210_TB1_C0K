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

        double Pair();
        double TwoPair();
        double ThreeOfAKind();
        double Straight();
        double Flush();
        double FullHouse();
        double FourOfAKind();
        double StraightFlush();
};

#endif