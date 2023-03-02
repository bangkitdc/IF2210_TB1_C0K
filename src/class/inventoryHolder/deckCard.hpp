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
        void deleteCard(Card);
        
    public:
        // friend class Player;
        // friend class Card;
        DeckCard();
        DeckCard(string);
        ~DeckCard();
        
        void shuffleCard();
        
        vector<Card> getCards();
        void setCards(vector<Card>);
        DeckCard& operator-(Card);
        DeckCard& operator+(Card);
        Card getCard();
        void displayDeckCard();
};

#endif