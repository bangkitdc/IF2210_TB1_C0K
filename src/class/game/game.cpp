#include "Game.hpp"

Game::Game() : d() {
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

void Game::setPrize(__uint128_t prize) {
    this->prize = prize;
}

void Game::printPrize(__uint128_t prize) {
    printf("%llu", (unsigned long long) prize);
}

__uint128_t Game::getPrize() {
    return this->prize;
}

void Game::printPlayersPoint() {
    cout << "<id> - name       - point\n";
    for (auto &p : playerTurn) {
        cout << "<p" << p.getId() << "> - " << left << setw(10) << p.getName() << " - ";
        printPrize(p.getPoint());
        cout << endl;
    }
    cout << endl;
}

vector<Player> Game::getPlayers() {
    vector<Player> res;

    for (int i = 0; i < playerTurn.size(); i ++) {
        res.push_back(getPlayer(i));
    }

    return res;
}

Player Game::getPlayer(int i) {
    return this->playerTurn[i];
}

Player Game::getFirstPlayer() {
    return this->playerTurn[0];
}

void Game::gameReset() {
    turn = 1;
    round = 1;
    prize = 0;
    gameEnd = false;
    programEnd = false;
    playerTurn.clear();
    d.resetDeckCard();
    Player::totalPlayer = 0;
}