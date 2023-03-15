#ifndef __GAME_HPP_
#define __GAME_HPP_

#include <iostream>
#include <deque>
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
        long long int prize;
        bool gameEnd;
        bool programEnd;
        deque<Player> playerTurn;
        DeckCard d;

    public:
        Game();
        void nextTurn();
        void nextRound();
        void setPrize(long long);
        long long getPrize();
        deque<Player> getPlayers();
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