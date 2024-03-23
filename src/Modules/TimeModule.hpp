/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** TimeModule
*/

#pragma once

#include <AEntity.hpp>
#include <GameObject.hpp>

class TimeModule : Module {
    public:
        TimeModule(GameObject *gameObject);
        ~TimeModule() = default;

        void update(GameObject *gameObject, std::vector<GameObject*> gameObjects) override;
    protected:
    private:
};
