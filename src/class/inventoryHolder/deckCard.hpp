#ifndef _DECKCARD_HPP_
#define _DECKCARD_HPP_

#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <algorithm>
#include <set>

#include "../cardValue/card.hpp"
#include "inventoryHolder.hpp"
#include "../exception/cardException.hpp"

using namespace std;

class DeckCard : public InventoryHolder {
    protected:
        vector<Card> cards;
    public:
        DeckCard();                             /* Default Constructor */
        ~DeckCard();                            /* Destructor  */
        void readFromFile(string);              /* I/O File */
        void shuffleCard();                     /* Shuffle Card */
        void setCards(vector<Card>);            /* Setter */
        void addCard(Card a);                   /* Setter */
        Card getCard();                         /* Getter */                
        Card getTopCard();                      /* Getter */
        vector<Card> getCards();                /* Getter */

        DeckCard& operator+(const Card &);      /* Operator Overloading */
        DeckCard &operator-(const Card &);      /* Operator Overloading */
        DeckCard &operator=(const DeckCard &);  /* Operator Overloading */
        
        void displayDeckCard();                 /* Display Deck */
        bool isDeckEmpty();                     /* Boolean Check Empty */
        void resetDeckCard();                   /* Reset Deck Card */
};

#endif