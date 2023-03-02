#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "../cardValue/card.hpp"
#include "../cardValue/card.hpp"
#include "../ability/ability.hpp"
#include "inventoryHolder.hpp"
#include "deckCard.hpp"
using namespace std;

class Player : public InventoryHolder {
    protected:
        string username;
        vector<Card> cardsP;
        // Ability ability;
        double point;
    public:
        // friend class Card;
        // friend class DeckCard;
        Player();
        Player(string,DeckCard*);
        ~Player();
        void setName(string);
        void addPoint(double);
        double getPoint()const;
        string getName()const;
        vector<Card> getCards();
        void displayPlayer();
        void setCard(DeckCard*);
};

#endif