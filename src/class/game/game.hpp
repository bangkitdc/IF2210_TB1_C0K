#ifndef __GAME_HPP_
#define __GAME_HPP_

#include <iostream>
#include <queue>
#include "../exception/exception.hpp"
#include "../exception/commandException.hpp"
#include "../inventoryHolder/player.hpp"
// #include "../inventoryHolder/deckCard.hpp"
using namespace std;

class Game {
    private:
        int round;
        bool gameEnd;
        queue<Player> playerTurn;
    public:

        Game();
        // ~Game();
        
        void startGame();
        string reqCommand();
        void process(string);

        void enqueuePlayer(Player);
        void dequeuePlayer(Player&);
        
        void nextRound();
};

#endif