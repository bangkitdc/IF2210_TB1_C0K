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
        const int id;
        string username;
        Ability * ability;
        vector<Card> cardsP;
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
        void setCards(vector<Card>);
        void displayPlayer();
        void setCard(DeckCard*);
        Player& operator+(Card);
        Player& operator-(Card);

        static int totalPlayer;
};

#endif