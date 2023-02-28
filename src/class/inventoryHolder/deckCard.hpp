#ifndef _DECKCARD_HPP_
#define _DECKCARD_HPP_

#include <iostream>
#include <vector>
#include "../cardValue/card.hpp"
#include "inventoryHolder.hpp"
using namespace std;

class DeckCard : public InventoryHolder {
    protected:
        vector<Card> cards;
    public:
        DeckCard();
        ~DeckCard();

        vector<Card> getCards();
};

#endif