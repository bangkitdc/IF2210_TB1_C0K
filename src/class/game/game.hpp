#ifndef __GAME_HPP_
#define __GAME_HPP_

#include "gameManager.hpp"
#include "../exception/exception.hpp"
#include "../exception/commandException.hpp"
#include "../inventoryHolder/player.hpp"
#include "../ability/deckAbility.hpp"

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