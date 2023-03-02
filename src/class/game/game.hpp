#ifndef __GAME_HPP_
#define __GAME_HPP_

#include <iostream>
#include <queue>
#include "../exception/exception.hpp"
#include "../inventoryHolder/player.hpp"
using namespace std;

class Game {
    private:
        int round;
        bool gameEnd;
        queue<Player> playerTurn;
    public:
        Game();
        
        void startGame();
        string reqCommand();
        void process(string);

        // void addPlayerTurn(Player);

        Game& operator<<(const Player&); // enqueue
        friend Game& operator>>(Game&, Player&); // dequeue
        void nextRound();
};

#endif