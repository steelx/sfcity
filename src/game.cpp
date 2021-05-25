
#include <SFML/System.hpp>

#include "game.hpp"
#include "game_state.hpp"

Game::Game() {
    loadTextures();
    window.create(sf::VideoMode(800, 600), "SF City");
    window.setFramerateLimit(60);

    background.setTexture(textureManager.getRef("background"));
}

Game::~Game() {
    while (!states.empty()) PopState();
}

void Game::PushState(GameState* state) {
    states.push(state);
}

void Game::PopState() {
    delete states.top();
    states.pop();
}

void Game::ChangeState(GameState *state) {
    if (!states.empty()) PopState();
    PushState(state);
}

GameState *Game::PeekState() {
    if (this->states.empty()) { return nullptr; }
    return this->states.top();
}

void Game::GameLoop() {
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        if (PeekState() == nullptr) continue;

        PeekState()->HandleInput();
        PeekState()->Update(dt);

        window.clear(sf::Color::Black);
        PeekState()->Draw(dt);
        window.display();
    }
}

void Game::loadTextures() {
    textureManager.LoadTexture("background", "assets/background.png");
}
