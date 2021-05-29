
#ifndef SFML_01_GAME_HPP
#define SFML_01_GAME_HPP

#include <stack>
#include <SFML/Graphics.hpp>
#include "texture_manager.hpp"
#include "tile.hpp"

// we define here to avoid cyclic dependencies
// we trust compiler it will find GameState class
class GameState;

class Game {
private:
    /// \brief loadTextures: should be used to initialize and loaded texture into game
    void loadTextures();
    void loadTiles();

public:
    const static int TileSize = 8;
    std::stack<GameState*> states;

    TextureManager textureManager;
    sf::RenderWindow window;
    sf::Sprite background;
    std::map<std::string, Tile> TileAtlas;

    void PushState(GameState* state);
    void PopState();
    void ChangeState(GameState* state);
    GameState* PeekState();

    void GameLoop();
    Game();
    ~Game();
};


#endif //SFML_01_GAME_HPP
