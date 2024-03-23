/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** No file there , just an epitech header example .
*/

#pragma once

#include <vector>

class GameObject;

class Module {
public:
    virtual void update(GameObject *gameObject, std::vector<GameObject*> gameObjects) = 0;
    virtual ~Module() = default;
};

