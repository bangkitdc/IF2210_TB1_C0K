#include "../class/game/game.hpp"

int main() {
    try {
        Game game;
        game.startGame();
    } catch (BaseException *e) {
        e->displayMessage();
    }
    return 0;
}