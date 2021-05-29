#include <SFML/Graphics.hpp>

#include "tile.hpp"

std::string tileTypeToStr(TileType type)
{
    switch(type)
    {
        default:
        case TileType::VOID:            return "Void";
        case TileType::GRASS:           return "Flatten";
        case TileType::FOREST:          return "Forest";
        case TileType::WATER:           return "Water";
        case TileType::RESIDENTIAL:     return "Residential Zone";
        case TileType::COMMERCIAL:      return "Commercial Zone";
        case TileType::INDUSTRIAL:      return "Industrial Zone";
    }
}

void Tile::Draw(sf::RenderWindow &window, float dt) {
    // Change the sprite to reflect the tile variant
    AnimHandler.ChangeAnim(TileVariant);

    // Update the animation
    AnimHandler.Update(dt);

    // Update the sprite
    Sprite.setTextureRect(AnimHandler.Bounds);

    // Draw the tile
    window.draw(Sprite);
}

void Tile::Update() {
    /* If the population is at the maximum value for the tile,
     * there is a small chance that the tile will increase its
     * building stage */
    if ((this->TileType == TileType::RESIDENTIAL ||
    this->TileType == TileType::COMMERCIAL ||
    this->TileType == TileType::INDUSTRIAL) &&
    this->Population == this->MaxPopPerLevel * (this->TileVariant+1) &&
    this->TileVariant < this->MaxLevels)
    {
        // TODO: fix random value gen
        if(rand() % int(1e4) < 1e2 / (this->TileVariant+1)) {
            ++this->TileVariant;
        }
    }
}
