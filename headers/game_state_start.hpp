
#ifndef SFML_01_GAME_STATE_START_HPP
#define SFML_01_GAME_STATE_START_HPP

#include <SFML/Graphics.hpp>

#include "game_state.hpp"

////////////////////////////////////////////////////////////
/// \brief GameState Start - game start menu
///
class GameStateStart : public GameState
{
private:
    sf::View view;
    void loadGame();

public:
    void Draw(const float dt);
    void Update(const float dt);
    void HandleInput();

    GameStateStart(Game* game);
};


#endif //SFML_01_GAME_STATE_START_HPP
