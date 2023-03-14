#include "Game.hpp"
#include "../inventoryHolder/player.hpp"
using namespace std;

Game::Game() {
    this->turn = 1;
    this->round = 1;
    this->gameEnd = false;
}

void Game::nextTurn() {
    if (this->turn == 7) {
        nextRound();
    }
    else {
        this->turn += 1;
    }
}

void Game::nextRound() {
    this->turn = 1;
    this->round += 1;
    Player temp = dequeuePlayer();
    enqueuePlayer(temp);
}

void Game::enqueuePlayer(Player player) {
    this->playerTurn.push_back(player);
}

Player Game::dequeuePlayer() {
    Player player = this->playerTurn.front();

    this->playerTurn.pop_front();
    return player;
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
