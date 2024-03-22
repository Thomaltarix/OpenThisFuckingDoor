/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** AEntitiy
*/

#include "AEntity.hpp"

void AEntity::display(sf::RenderWindow window)
{
    for (auto& texture : _textures) {
        sf::Sprite sprite;
        sprite.setTexture(texture.second);
        sprite.setScale(_size.first / texture.second.getSize().x, _size.second / texture.second.getSize().y);
        sprite.setPosition((sf::Vector2f){_pos.first, _pos.second});
        window.draw(sprite);
    }
}

void AEntity::setTextures(std::vector<std::string> strings)
{
    _textures.clear();
    for (auto& path : strings) {
        if (_textures.find(path) != _textures.end())
            continue;
        sf::Texture texture;
        if (!texture.loadFromFile(path))
            throw Error("Failed to load texture.");
        _textures[path] = texture;
    }
}
