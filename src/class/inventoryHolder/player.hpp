#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
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
class tableCard;

class Player : public InventoryHolder {
    protected:
        int id;
        string username;
        Ability * ability;
        vector<Card> cardsP;
        __uint128_t point;
    public:
        // friend class Card;
        // friend class DeckCard;
        Player();
        Player(string);
        Player(string,DeckCard&,int);
        ~Player();
        void setName(string);
        void addPoint(__uint128_t);

        int getId() const;
        __uint128_t getPoint()const;
        string getName()const;
        vector<Card> getCards();
        void setCards(vector<Card>);
        void displayPlayer(bool displayPoint = true);
        void displayPlayerCard(int);
        void displayPlayerCards();
        void setCard(DeckCard&);
        void setCardN(DeckCard &, int);
        void setCardDepan(Card);
        void setCardBelakang(Card);
        Card getPlayerCard(int i);
        Card getPlayerCardWithoutPop(int i);

        Ability* getAbility();
        void setAbility(Ability*);
        Player& operator+(const Card &);
        Player& operator+(DeckCard &);

        void addCard(const Card &);
        void addCardFromDeck(DeckCard &);

        Player& operator-(const Card &);
        Player& operator-(DeckCard &);
        Player& operator=(const Player &);
        vector<Card> evaluateCard(tableCard a);
        double getValueGeneric();
        void resetPlayerCard();
        static int totalPlayer;

        friend class ReRoll;
        friend class DeckAbility;
        friend class Game;
};

void moveAllTableCardToPlayer(Player &, tableCard &);

#endif