#ifndef _TABLECARD_HPP_
#define _TABLECARD_HPP_

#include <iostream>
#include <vector>
#include "../cardValue/card.hpp"
#include "deckCard.hpp"
#include "inventoryHolder.hpp"
#include "player.hpp"
#include "../exception/cardException.hpp"
#include "../../utility/utility.hpp"


using namespace std;

class Player;
class tableCard : public InventoryHolder{
    protected:
        vector<Card> Tcards;
        vector<int> kartuMilik;
    public:
        tableCard();                        /* Default Constructor */
        ~tableCard();                       /* Destructor */
        void setTCard(DeckCard*);           /* Setter */
        void setCards(vector<Card>);        /* Setter */

        vector<Card> getCards();            /* Getter */
        Card getFirstCard();                /* Getter */
        Card getCard();                     /* Getter */
        Card getCardWithoutPop(int i);      /* Getter */
        int getMilik(int i);                /* Getter */

        void displayTCard();                /* I/O Console */
        
        void clearCards();                  /* Clear Table Cards */
        void clearMilik();                  /* Clear Milik */

        void addCard(Card);                 /* Add Card */
        void addMilik(int i);               /* Add Milik */

        tableCard& operator+(DeckCard &);   /* Operator Overloading */
        tableCard& operator-(DeckCard &);   /* Operator Overloading */

        bool isTCardEmpty();                /* Operator */
        void sortTableCard();               /* Sort Table Card */
};

void addPlayerCard(tableCard &, Player &, int); /* Add Player Card From Table*/

#endif