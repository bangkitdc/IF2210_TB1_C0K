#ifndef _TABLECARD_HPP_
#define _TABLECARD_HPP_

#include <iostream>
#include <vector>
#include "../cardValue/card.hpp"
#include "deckCard.hpp"
#include "player.hpp"
#include "inventoryHolder.hpp"

class tableCard : public InventoryHolder{
    protected:
    vector<Card> Tcards;
    public:
    tableCard();
    ~tableCard();
    void setTCard(DeckCard*);
    void displayTCard();
    vector<Card> getCards();
    void setCards(vector<Card>);
    

};


#endif