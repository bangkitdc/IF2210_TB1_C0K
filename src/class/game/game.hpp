#ifndef __GAME_HPP_
#define __GAME_HPP_

#include <iostream>
#include <queue>
#include "../exception/exception.hpp"
using namespace std;

class Game {
    private:
        int round;
        bool gameEnd;
    public:
        Game();
        
        void startGame();
        string reqCommand();
        void process(string);

        void nextRound();
};

#endif