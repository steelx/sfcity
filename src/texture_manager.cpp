//
// Created by ajink on 25-05-2021.
//

#include "texture_manager.hpp"

void TextureManager::LoadTexture(const std::string &name, const std::string &filePath) {
    sf::Texture tex{};
    tex.loadFromFile(filePath);
    textures[name] = tex;
}

sf::Texture &TextureManager::getRef(const std::string &textureName) {
    return textures.at(textureName);
}
