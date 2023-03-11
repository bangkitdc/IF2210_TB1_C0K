#ifndef __GAME_HPP_
#define __GAME_HPP_

#include "gameManager.hpp"

class Game : public GameManager {
    public:
        Game();
        
        void startGame();

        void inputPlayer(DeckCard &);

        string reqCommand();
        void process(string);

        void enqueuePlayer(Player);
        Player dequeuePlayer();
        void printQueue();
};

#endif