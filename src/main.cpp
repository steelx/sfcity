#include "game.hpp"
#include "game_state_start.hpp"

int main() {
    Game game;

    game.PushState(new GameStateStart(&game));
    game.GameLoop();

    return 0;
}
