
#ifndef SFML_01_GAME_HPP
#define SFML_01_GAME_HPP

#include <stack>
#include <SFML/Graphics.hpp>
#include "texture_manager.hpp"

// we define here to avoid cyclic dependencies
// we trust compiler it will find GameState class
class GameState;

class Game {
private:
    /// \brief loadTextures: should be used to initialize and loaded texture into game
    void loadTextures();

public:
    std::stack<GameState*> states;

    TextureManager textureManager;
    sf::RenderWindow window;
    sf::Sprite background;

    void PushState(GameState* state);
    void PopState();
    void ChangeState(GameState* state);
    GameState* PeekState();

    void GameLoop();
    Game();
    ~Game();
};


#endif //SFML_01_GAME_HPP
