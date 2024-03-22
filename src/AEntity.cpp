/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** AEntitiy
*/

#include "AEntity.hpp"

void AEntity::setTextures(std::vector<std::string> strings)
{
    _textures.clear();
    for (auto& path : strings) {
        sf::Texture texture;
        if (!texture.loadFromFile(path))
            throw Error("Failed to load texture.");
        _textures.push_back(texture);
    }
}
