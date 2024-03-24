/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** Door
*/

#include <HitboxModule.hpp>
#include "Door.hpp"
#include "Game.h"
#include <Game.hpp>
#include "GameObject.hpp"

Door::Door(std::string str)
{
    addModule<DisplayModule>();
    addModule<CollisionModule>();
    data["texture"] = str;
    data["x"] = 2462;
    data["y"] = 2452;
    data["TextureSize"] = std::pair<int, int>(126, 131);
}
