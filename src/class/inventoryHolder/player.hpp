#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

#include "../cardValue/card.hpp"
#include "../ability/ability.hpp"
#include "inventoryHolder.hpp"
#include "deckCard.hpp"
#include "../inventoryHolder/tableCard.hpp"
#include "../exception/cardException.hpp"

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
        Player();                                               /* Default Constructor */                      
        Player(string);                                         /* Constructor */
        Player(string,DeckCard&,int);                           /* Constructor */
        ~Player();                                              /* Destructor */
        void setName(string);                                   /* Setter */

        void addPoint(__uint128_t);                             /* Setter */
        void setCards(vector<Card>);                            /* Setter */
        void setCard(DeckCard &);                               /* Setter */
        void setCardN(DeckCard &, int);                         /* Setter */
        void setCardDepan(Card);                                /* Setter */
        void setCardBelakang(Card);                             /* Setter */
        void setAbility(Ability*);                              /* Setter */

        int getId() const;                                      /* Getter */
        __uint128_t getPoint()const;                            /* Getter */
        string getName()const;                                  /* Getter */
        vector<Card> getCards();                                /* Getter */
        Card getPlayerCard(int i);                              /* Getter */
        Card getPlayerCardWithoutPop(int i);                    /* Getter */
        Ability *getAbility();                                  /* Getter */
        double getValueGeneric();                               /* Getter */

        void displayPlayer(bool displayPoint = true);           /* I/O Console */
        void displayPlayerCard(int, bool displaySpace = true);  /* I/O Console */
        void displayPlayerCards();                              /* I/O Console */

        Player& operator+(const Card &);                        /* Operator Overloading */
        Player& operator+(DeckCard &);                          /* Operator Overloading */
        Player &operator-(const Card &);                        /* Operator Overloading */
        Player &operator-(DeckCard &);                          /* Operator Overloading */
        Player &operator=(const Player &);                      /* Operator Overloading */
        bool operator>(const Player &);                         /* Operator Overloading */
        bool operator<(const Player &);                         /* Operator Overloading */
        bool operator==(const Player &);                        /* Operator Overloading */

        void addCard(const Card &);                             /* Add Card */
        void addCardFromDeck(DeckCard &);                       /* Add Card From Deck */

        void resetPlayerCard();                                 /* Reset Player Card */

        static int totalPlayer;                                 /* Attribute */

        friend class ReRoll;                                    /* Friend Function */
        friend class DeckAbility;                               /* Friend Function */
        friend class Game;                                      /* Friend Function */
};

void moveAllTableCardToPlayer(Player &, tableCard &);           /* Move All Table Card To Player */

#endif