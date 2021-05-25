//
// Created by Ajinkya on 23-05-2021.
//

#ifndef SFML_01_GAME_STATE_HPP
#define SFML_01_GAME_STATE_HPP

#include "game.hpp"

class GameState {
public:
    Game* game;
    virtual void Draw(const float dt) {}
    virtual void Update(const float dt) {}
    virtual void HandleInput() {}
};


#endif //SFML_01_GAME_STATE_HPP
