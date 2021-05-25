//
// Created by ajink on 23-05-2021.
//

#ifndef SFML_01_GAME_STATE_EDITOR_HPP
#define SFML_01_GAME_STATE_EDITOR_HPP

#include "game_state.hpp"

///
/// \brief GameState Editor - game world & game HUD
///
class GameStateEditor : public GameState
{
private:
    sf::View gameView;
    sf::View guiView;

public:
    void Draw(const float dt);
    void Update(const float dt);
    void HandleInput();

    GameStateEditor(Game* game);
};


#endif //SFML_01_GAME_STATE_EDITOR_HPP
