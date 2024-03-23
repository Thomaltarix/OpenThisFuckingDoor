/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** AEntitiy
*/

#include "AEntity.hpp"

void AEntity::display(sf::RenderWindow window, enum State state)
{
    int i = 0;

    for (auto& texture : _textures) {
        if (i == state) {
            sf::Sprite sprite;
            sprite.setTexture(texture.second);
            sprite.setScale(_size.first / texture.second.getSize().x, _size.second / texture.second.getSize().y);
            sprite.setPosition((sf::Vector2f){_pos.first, _pos.second});
            window.draw(sprite);
        }
        i++;
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
