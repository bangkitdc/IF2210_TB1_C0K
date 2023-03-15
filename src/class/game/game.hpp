#ifndef __GAME_HPP_
#define __GAME_HPP_

#include <iostream>
#include <deque>
#include <cstdint>
#include <cstdio>
#include <iomanip>

#include "../inventoryHolder/player.hpp"
#include "../inventoryHolder/deckCard.hpp"
#include "genericFunction.hpp"

using namespace std;

#pragma once
class Player;
class DeckCard;

class Game {
    protected:
        int turn;
        int round;
        __uint128_t prize;
        bool gameEnd;
        bool programEnd;
        deque<Player> playerTurn;
        DeckCard d;

    public:
        Game();                         /* Default Constructor */
        void nextTurn();                /* Next Turn */
        void nextRound();               /* Next Round */

        void setPrize(__uint128_t);     /* Setter */

        __uint128_t getPrize();         /* Getter */
        vector<Player> getPlayers();     /* Getter */
        Player getFirstPlayer();        /* Getter */
        Player getPlayer(int);          /* Getter */

        void printPrize(__uint128_t);   /* I/O Console */
        void printPlayersPoint();       /* I/O Console */
        
        void enqueuePlayer(Player);     /* Enqueue */
        Player dequeuePlayer();         /* Dequeue */

        void gameReset();               /* Reset Game */

        friend class DeckAbility;       /* Friend Function */
        friend class Swap;              /* Friend Function */
        friend class Switch;            /* Friend Function */
        friend class Reverse;           /* Friend Function */
        friend class AbilityLess;       /* Friend Function */
        friend class ReRoll;            /* Friend Function */
};

#endif