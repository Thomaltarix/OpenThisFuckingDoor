/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** Wall
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Wall.hpp"
#include "PositionModule.hpp"
#include "CollisionModule.hpp"
#include "DisplayModule.hpp"

Wall::Wall(std::string str, std::pair<int, int> pos, std::pair<int, int> size)
{
    sf::Texture texture;

    texture.loadFromFile(str);
    addModule<PositionModule>();
    addModule<CollisionModule>();
    addModule<DisplayModule>();
    data["texture"] = texture;
    data["x"] = pos.first;
    data["y"] = pos.second;
    data["TextureSize"] = size;
}
