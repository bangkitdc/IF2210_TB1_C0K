#ifndef _TABLECARD_HPP_
#define _TABLECARD_HPP_

#include <iostream>
#include <vector>
#include "../cardValue/card.hpp"
#include "deckCard.hpp"
#include "inventoryHolder.hpp"
#include "player.hpp"

class Player;
class tableCard : public InventoryHolder{
    protected:
        vector<Card> Tcards;
        vector<int> kartuMilik;
    public:
        tableCard();
        ~tableCard();
        void setTCard(DeckCard*);
        void displayTCard();
        vector<Card> getCards();
        Card getFirstCard();
        Card getCard();
        Card getCardWithoutPop(int i);
        void clearCards();


        void addCard(Card);
        void addMilik(int i);
        int getMilik(int i);
        void clearMilik();

        void setCards(vector<Card>);
        tableCard& operator+(DeckCard &);

        tableCard& operator-(DeckCard &);

        bool isTCardEmpty();

        void sortTableCard();
};

void addPlayerCard(tableCard &, Player &, int);

#endif