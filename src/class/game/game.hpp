#ifndef __GAME_HPP_
#define __GAME_HPP_

#include <iostream>
#include <deque>
// #include "../inventoryHolder/player.hpp"
// #include "../cardValue/cardValue.hpp"
using namespace std;

#pragma once
class Player;

class Game {
    protected:
        int round;
        int prize;
        bool gameEnd;
        deque<Player> playerTurn;
    public:
        Game();
        void nextRound();
        void setPrize(int);
        int getPrize();
        deque<Player> getPlayer();
        friend class DeckAbility;
        friend class Swap;
        friend class Switch;
};

#endif