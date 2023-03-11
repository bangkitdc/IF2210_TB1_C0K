#ifndef __GAMEMANAGER_HPP_
#define __GAMEMANAGER_HPP_

#include <iostream>
#include <deque>
#include "../exception/exception.hpp"
#include "../exception/commandException.hpp"
#include "../inventoryHolder/player.hpp"
// #include "../cardValue/cardValue.hpp"
using namespace std;

class GameManager {
    protected:
        int round;
        int prize;
        bool gameEnd;
        deque<Player> playerTurn;
    public:
        GameManager();
        void nextRound();
        void setPrize(int);
        int getPrize();
};

#endif