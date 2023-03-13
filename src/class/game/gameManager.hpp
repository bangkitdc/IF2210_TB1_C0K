#ifndef __GAMEMANAGER_HPP_
#define __GAMEMANAGER_HPP_

#include "game.hpp"
#include "../exception/exception.hpp"
#include "../exception/commandException.hpp"
#include "../inventoryHolder/player.hpp"
#include "../inventoryHolder/tableCard.hpp"
#include "../ability/deckAbility.hpp"

class GameManager : public Game {
    public:
        GameManager();
        
        void startGame();

        void inputPlayer();

        string reqCommand();
        void process(string);

        void enqueuePlayer(Player);
        Player dequeuePlayer();
        void printQueue();
};

#endif