#ifndef __GAMEMANAGER_HPP_
#define __GAMEMANAGER_HPP_

#include "game.hpp"
#include <vector>
#include <string>
#include "../exception/exception.hpp"
#include "../exception/commandException.hpp"
#include "../exception/cardException.hpp"
#include "../exception/numberException.hpp"
#include "../inventoryHolder/player.hpp"
#include "../inventoryHolder/tableCard.hpp"
#include "../ability/deckAbility.hpp"

class GameManager : public Game {
    public:
        GameManager();
        
        void startGame();

        void inputPlayer(int);
        void inputPlayer(int, DeckCard&, int);
        string inputFile();
        int inputOpsi();
        int inputGame();

        string reqCommand();
        void process(string);

        void printQueue();

        bool isInteger(const string &);
        void CheckWin(deque<Player> &);

        /* BONUS */

        int inputCangkul(int, int);
        void CheckWin2(deque<Player> &);
        void displayPlayerCardWithColor(Player &, string);
        vector<int> countPlayerCardWithColor(Player &, string);
        void evaluateQueue(tableCard &);
        int findIdxWithId(int);
};

#endif