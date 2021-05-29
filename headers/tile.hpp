//
// Created by Ajinkya on 27-05-2021.
//

#ifndef SFML_01_TILE_HPP
#define SFML_01_TILE_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "animation_handler.hpp"

enum class TileType {
    VOID, GRASS, FOREST, WATER, RESIDENTIAL, COMMERCIAL, INDUSTRIAL, ROAD
};

/// tileTypeToStr function
std::string tileTypeToStr(TileType type);

class Tile {
public:
    AnimationHandler AnimHandler;
    sf::Sprite Sprite;
    TileType TileType;

    /// Tile variant, allowing for different looking versions of the same tile
    int TileVariant;

    /// Region IDs of the tile, tiles in the same region are connected.
    /// First is for transport
    unsigned int Regions[1];

    /// Placement cost of the tile
    unsigned int Cost;

    /// Current residents / employees
    double Population;
    /// Maximum population per growth stage / tile variant */
    unsigned int MaxPopPerLevel;
    /// Maximum number of building levels
    unsigned int MaxLevels;
    /// Production output per customer/worker per day, either monetary or goods */
    float Production;
    /// Goods stored
    float  StoredGoods;

    Tile() {}
    Tile(const unsigned int tileSize,
         const unsigned int height, sf::Texture& texture,
         const std::vector<Animation>& animations,
         const enum TileType tileType,
         const unsigned int cost,
         const unsigned int maxPopPerLevel,
         const unsigned int maxLevels)
    {
        this->TileType = tileType;
        this->TileVariant = 0;
        this->Regions[0] = 0;

        this->Cost = cost;
        this->Population = 0;
        this->MaxPopPerLevel = maxPopPerLevel;
        this->MaxLevels = maxLevels;
        this->Production = 0;
        this->StoredGoods = 0;

        this->Sprite.setOrigin(sf::Vector2f(0.0f, float(tileSize*(height-1))));
        this->Sprite.setTexture(texture);
        this->AnimHandler.FrameSize = sf::IntRect(0,0, tileSize*2, tileSize*height);
        for (auto animation : animations) {
            this->AnimHandler.AddAnim(animation);
        }
        this->AnimHandler.Update(0.0f);
    }

    void Draw(sf::RenderWindow& window, float dt);
    void Update();

    /// Return a string containing the display cost of the tile
    std::string GetCost() {
        return std::to_string(this->Cost);
    }
};


#endif //SFML_01_TILE_HPP
