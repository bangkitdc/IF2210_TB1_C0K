#include "Game.hpp"
#include "../inventoryHolder/player.hpp"
using namespace std;

Game::Game() {
    this->round = 1;
    this->gameEnd = false;
}

void Game::nextRound() {
    if (this->round == 6) {
        this->round = 1;
    } else {
        this->round += 1;
    }
}

void Game::setPrize(int prize) {
    this->prize = prize;
}

int Game::getPrize() {
    return this->prize;
}

deque<Player> Game::getPlayers() {
    return this->playerTurn;
}

Player Game::getPlayer(int i) {
    return this->playerTurn[i];
}

Player Game::getFirstPlayer() {
    return this->playerTurn[0];
}
