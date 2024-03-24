/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** Player
*/

#include <HitboxModule.hpp>
#include <MovementModule.hpp>
#include "Player.hpp"
#include "Game.h"
#include <Game.hpp>
#include "GameObject.hpp"

Player::Player(std::string str, std::pair<int, int> pos, std::pair<int, int> size)
{
    addModule<PlayerModule>();
    data["texture"] = str;
    data["x"] = pos.first;
    data["y"] = pos.second;
    data["TextureSize"] = size;
}

void Player::displayPlayer(void)
{
    float x = (float)std::any_cast<int>(data["x"]);
    float y = (float)std::any_cast<int>(data["y"]);
    std::pair size = std::any_cast<std::pair<int, int>>(data["TextureSize"]);
    sf::View view((sf::FloatRect){x - (192 / 2) + (size.first / 2), y - (108 / 2) + (size.second / 2), 192, 108});
    sf::Sprite sprite;

    sf::Texture texture;
    texture.loadFromFile(std::any_cast<std::string>(data["texture"]));
    sprite.setTexture(texture);
    sprite.setPosition((sf::Vector2f){(float)x, (float)y});
    game.getWindow().setView(view);
    game.getWindow().draw(sprite);
}
