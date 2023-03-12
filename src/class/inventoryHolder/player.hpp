#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "../cardValue/card.hpp"
// #include "../ability/ability.hpp"
#include "inventoryHolder.hpp"
#include "deckCard.hpp"
#include "../inventoryHolder/tableCard.hpp"
using namespace std;

#pragma once
class Ability;
class DeckAbility;
class Game;

class Player : public InventoryHolder {
    protected:
        int id;
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

        int getId() const;
        double getPoint()const;
        string getName()const;
        vector<Card> getCards();
        void setCards(vector<Card>);
        void displayPlayer();
        void displayPlayerCard(int i);
        void setCard(DeckCard*);
        Ability* getAbility();
        void setAbility(Ability*);
        Player& operator+(const Card &);
        Player& operator+(DeckCard &);
        Player& operator-(const Card &);
        Player& operator-(DeckCard &);
        Player& operator=(const Player &);
        vector<Card> evaluateCard(tableCard a);
        static int totalPlayer;
        friend class DeckAbility;
        friend class Game;
};

#endif