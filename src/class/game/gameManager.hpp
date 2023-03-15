#ifndef __GAMEMANAGER_HPP_
#define __GAMEMANAGER_HPP_

#include <vector>
#include <filesystem>
#include <iostream>
#include <string>
#include <conio.h>

#include "game.hpp"
#include "../../utility/utility.hpp"
#include "../exception/exception.hpp"
#include "../exception/commandException.hpp"
#include "../exception/cardException.hpp"
#include "../exception/numberException.hpp"
#include "../inventoryHolder/player.hpp"
#include "../inventoryHolder/tableCard.hpp"
#include "../ability/deckAbility.hpp"
#include "../cardValue/combination.hpp"
#include "genericFunction.hpp"

using namespace std;

class GameManager : public Game {
    public:
        GameManager();                                          /* Default Constructor */
        
        void inputPlayer(int);                                  /* I/O Console */
        void inputPlayer(int, DeckCard &, int);                 /* I/O Console */
        string inputFile();                                     /* I/O Console */
        int inputOpsi();                                        /* I/O Console */
        int inputGame();                                        /* I/O Console */
        string reqCommand();                                    /* I/O Console */
        void printQueue();                                      /* I/O Console */

        void startGame();                                       /* Start */
        void process(string);                                   /* Process Command */
        bool isInteger(const string &);                         /* Validator */
        void CheckWin(deque<Player> &);                         /* Validator */

        /* BONUS */

        int inputCangkul(int, int);                             /* I/O Console */
        void displayPlayerCardWithColor(Player &, string);      /* I/O Console */
        void CheckWin2(deque<Player> &);                        /* Validator */
        void evaluateQueue(tableCard &);                        /* Validator */
        vector<int> countPlayerCardWithColor(Player &, string); /* Getter */
        int findIdxWithId(int);                                 /* Getter */
};

#endif