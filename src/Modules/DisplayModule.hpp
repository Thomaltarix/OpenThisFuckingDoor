/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** DisplayModule
*/

#pragma once

#include <AEntity.hpp>
#include <GameObject.hpp>

class DisplayModule : Module {
    public:
        DisplayModule(GameObject *gameObject);
        ~DisplayModule() = default;

        void update(GameObject *gameObject, std::vector<GameObject*> gameObjects) override;
};
