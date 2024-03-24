/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** Ground
*/

#include "Ground.hpp"
#include "PositionModule.hpp"
#include "DisplayModule.hpp"

Ground::Ground(sf::Texture texture, std::pair<int, int> pos, std::pair<int, int> size)
{
    addModule<PositionModule>();
    addModule<DisplayModule>();
    data["texture"] = texture;
    data["x"] = pos.first;
    data["y"] = pos.second;
    data["TextureSize"] = size;
}
