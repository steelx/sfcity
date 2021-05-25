
#include "game_state_start.hpp"
#include "game_state_editor.hpp"

void GameStateStart::Draw(const float dt) {
    game->window.setView(view);

    game->window.clear(sf::Color::Black);
    game->window.draw(game->background);
}

void GameStateStart::Update(const float dt) {

}

void GameStateStart::HandleInput() {
    sf::Event event{};

    while (game->window.pollEvent(event))
    {
        switch (event.type) {
            case sf::Event::Closed:
            {
                game->window.close();
                break;
            }
            case sf::Event::Resized:
            {
                view.setSize(event.size.width, event.size.height);
                game->background.setPosition(game->window.mapPixelToCoords(sf::Vector2i(0, 0)));
                game->background.setScale(
                    float(event.size.width) / float(game->background.getTexture()->getSize().x),
                    float(event.size.height) / float(game->background.getTexture()->getSize().y)
                );
                break;
            }
            case sf::Event::KeyReleased:
            {
                if(event.key.code == sf::Keyboard::Escape) game->window.close();
                else if(event.key.code == sf::Keyboard::Space) loadGame();
                break;
            }

            default: break;
        }
    }

}

GameStateStart::GameStateStart(Game *game) {
    this->game = game;
    sf::Vector2f pos(this->game->window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);
}

void GameStateStart::loadGame() {
    this->game->PushState(new GameStateEditor(this->game));
}
