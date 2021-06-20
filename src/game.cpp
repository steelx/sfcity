
#include <SFML/System.hpp>

#include "game.hpp"
#include "game_state.hpp"

Game::Game() {
    window.create(sf::VideoMode(800, 600), "SF City");
    window.setFramerateLimit(60);

    loadTextures();
    loadTiles();
    background.setTexture(textureManager.GetRef("background"));
}

Game::~Game() {
    while (!states.empty()) PopState();
}

void Game::PushState(GameState *state) {
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

    while (window.isOpen()) {
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
    textureManager.LoadTexture("grass", "assets/grass.png");
    textureManager.LoadTexture("forest", "assets/forest.png");
    textureManager.LoadTexture("water", "assets/water.png");
    textureManager.LoadTexture("residential", "assets/residential.png");
    textureManager.LoadTexture("commercial", "assets/commercial.png");
    textureManager.LoadTexture("industrial", "assets/industrial.png");
    textureManager.LoadTexture("road", "assets/road.png");

    textureManager.LoadTexture("background", "assets/background.png");
}

void Game::loadTiles() {
    Animation staticAnim(0, 0, 1.0f);

    TileAtlas["grass"] = Tile(
            Game::TileSize, 1,
            textureManager.GetRef("grass"),
            {staticAnim},
            TileType::GRASS,
            50, 0, 1
    );

    TileAtlas["forest"] = Tile(
            Game::TileSize,
            1,
            textureManager.GetRef("forest"),
            {staticAnim},
            TileType::FOREST,
            100, 0, 1
    );

    TileAtlas["water"] = Tile(
            Game::TileSize,
            1,
            textureManager.GetRef("water"),
            {
                    Animation(0, 3, 0.5f),
                    Animation(0, 3, 0.5f),
                    Animation(0, 3, 0.5f),
            },
            TileType::WATER,
            0, 0, 1
    );

    TileAtlas["residential"] = Tile(
            Game::TileSize,
            2,
            textureManager.GetRef("residential"),
            {
                    staticAnim, staticAnim, staticAnim,
                    staticAnim, staticAnim, staticAnim
            },
            TileType::RESIDENTIAL,
            300, 50, 6
    );

    TileAtlas["commercial"] = Tile(
            Game::TileSize,
            2,
            textureManager.GetRef("commercial"),
            {
                    staticAnim, staticAnim, staticAnim, staticAnim
            },
            TileType::COMMERCIAL,
            300, 50, 4
    );

    TileAtlas["industrial"] = Tile(
            Game::TileSize,
            2,
            textureManager.GetRef("industrial"),
            {
                    staticAnim, staticAnim, staticAnim, staticAnim
            },
            TileType::INDUSTRIAL,
            300, 50, 4
    );

    TileAtlas["road"] = Tile(
            Game::TileSize,
            1,
            textureManager.GetRef("road"),
            {
                    staticAnim, staticAnim, staticAnim,
                    staticAnim, staticAnim, staticAnim,
                    staticAnim, staticAnim, staticAnim,
                    staticAnim, staticAnim
            },
            TileType::ROAD,
            100, 0, 1
    );
}
