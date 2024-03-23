/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** TimeModule
*/

#include "TimeModule.hpp"

TimeModule::TimeModule(GameObject *gameObject)
{
    if (gameObject->hasModule<TimeModule>())
        throw std::runtime_error("GameObject already has a TimeModule!");
    if (gameObject->data.find("clock") == gameObject->data.end())
        gameObject->data["clock"] = new sf::Clock;
}

void TimeModule::update(GameObject *gameObject, std::vector<GameObject*> gameObjects)
{
    return;
}