#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "../cardValue/card.hpp"
#include "../ability/ability.hpp"
#include "inventoryHolder.hpp"
using namespace std;

class Player : public InventoryHolder {
    protected:
        string username;
        vector<Card> cards;
        Ability * ability;
    public:
        Player();
        Player(string);
        ~Player();

        vector<Card> getCards();
};

#endif