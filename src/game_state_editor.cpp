#include <iostream>
#include "game_state_editor.hpp"

void GameStateEditor::Draw(const float dt) {
    game->window.clear(sf::Color::Black);
    game->window.draw(game->background);
}

void GameStateEditor::Update(const float dt) {

}

void GameStateEditor::HandleInput() {
    sf::Event event{};

    while (game->window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
            {
                game->window.close();
                break;
            }
            /* Resize the window */
            case sf::Event::Resized:
            {
                gameView.setSize(event.size.width, event.size.height);
                guiView.setSize(event.size.width, event.size.height);
                game->background.setPosition(
                        game->window.mapPixelToCoords(sf::Vector2i(0,0), guiView)
                );
                game->background.setScale(
                        float(event.size.width) / float(game->background.getTexture()->getSize().x),
                        float(event.size.height) / float(game->background.getTexture()->getSize().y)
                );
                break;
            }
            case sf::Event::KeyReleased:
            {
                if(event.key.code == sf::Keyboard::Escape) {
                    std::cout << "No Escape from here!!" << std::endl;
                }
                break;
            }

            default: break;
        }
    }
}

GameStateEditor::GameStateEditor(Game *game) {
    std::cout << "GameState -> Editor" << std::endl;
    this->game = game;
    sf::Vector2f pos(this->game->window.getSize());
    this->guiView.setSize(pos);
    this->gameView.setSize(pos);
    pos *= 0.5f;
    this->guiView.setCenter(pos);
    this->gameView.setCenter(pos);
}
