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
        void setCards(vector<Card>);
        void addCard(Card a);
        Card getCard();
        vector<Card> getCards();
        DeckCard& operator-(const Card &);
        DeckCard& operator+(const Card &);
        DeckCard& operator=(const DeckCard &);
        void displayDeckCard();
};

#endif