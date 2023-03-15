#ifndef __GAME_HPP_
#define __GAME_HPP_

#include <iostream>
#include <deque>
#include <cstdint>
#include <cstdio>
// #include "../inventoryHolder/player.hpp"
// #include "../cardValue/cardValue.hpp"
#include "../inventoryHolder/deckCard.hpp"
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
        Game();
        void nextTurn();
        void nextRound();
        void setPrize(__uint128_t);
        __uint128_t getPrize();
        void printPrize(__uint128_t);
        deque<Player> getPlayers();
        void printPlayersPoint();
        void enqueuePlayer(Player);
        Player dequeuePlayer();
        Player getFirstPlayer();
        Player getPlayer(int);

        void gameReset();

        friend class DeckAbility;
        friend class Swap;
        friend class Switch;
        friend class Reverse;
        friend class AbilityLess;
        friend class ReRoll;
};

#endif