#include "GameManager.hpp"
using namespace std;

GameManager::GameManager() {
    this->round = 1;
    this->gameEnd = false;
}

void GameManager::nextRound() {
    if (this->round == 6) {
        this->round = 1;
    } else {
        this->round += 1;
    }
}

void GameManager::setPrize(int prize) {
    this->prize = prize;
}

int GameManager::getPrize() {
    return this->prize;
}