#ifndef __GAME_HPP_
#define __GAME_HPP_

#include <iostream>
#include <deque>
#include "../exception/exception.hpp"
#include "../exception/commandException.hpp"
#include "../inventoryHolder/player.hpp"
// #include "../cardValue/cardValue.hpp"
using namespace std;

class Game {
    private:
        int round;
        int prize;
        bool gameEnd;
        deque<Player> playerTurn;
    public:
        Game();
        
        void startGame();

        void inputPlayer(DeckCard &);

        string reqCommand();
        void process(string);

        void enqueuePlayer(Player);
        Player dequeuePlayer();
        void printQueue();

        void nextRound();

        void setPrize(int);
        int getPrize();
};

#endif