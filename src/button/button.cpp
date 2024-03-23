/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** button
*/

#include "button.hpp"

Button::Button(std::string path, std::pair<float, float> pos, std::pair<float, float> size, ButtonType type)
{
    if (!_texture.loadFromFile(path))
        throw Error("Failed to load image");
    _sprite.setTexture(_texture);
    if (type == DOOR) {
        _sprite.setTextureRect(sf::IntRect(0,0,80,66));
    }
    if (type == BUTTON) {
        _sprite.setTextureRect(sf::IntRect(0,0,500,150));
    }
}
