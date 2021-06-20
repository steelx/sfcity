//
// Created by Ajinkya on 25-05-2021.
//

#ifndef SFML_01_TEXTURE_MANAGER_HPP
#define SFML_01_TEXTURE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

///
/// \brief texture manager to store our textures,
/// which will be part of the Game class
class TextureManager {
private:
    std::map<std::string, sf::Texture> textures;

public:
    void LoadTexture(const std::string& name, const std::string& filePath);

    /// Translate an id into a reference
    sf::Texture& GetRef(const std::string& textureName);

    TextureManager() {}
};


#endif //SFML_01_TEXTURE_MANAGER_HPP
