/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** Pillar
*/

#include "Pillar.hpp"
#include <HitboxModule.hpp>
#include <MovementModule.hpp>
#include "Game.h"
#include <Game.hpp>
#include "GameObject.hpp"

void pillar_action(GameObject *player, GameObject *pillar)
{
    pillar->data["texture"] = "../assets/totem_pillar/pillar_finished.png";
}

Pillar::Pillar(std::string str, std::pair<int, int> pos, std::pair<int, int> size)
{
    addModule<InteractionModule>();
    addModule<DisplayModule>();
    data["texture"] = str;
    data["x"] = pos.first;
    data["y"] = pos.second;
    data["TextureSize"] = size;
    data["actionEffect"] = &pillar_action;
}

