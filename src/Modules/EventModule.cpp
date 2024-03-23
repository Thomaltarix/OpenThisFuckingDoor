/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** No file there , just an epitech header example .
*/

#include "EventModule.hpp"

EventModule::EventModule(GameObject *gameObject)
{
    if (gameObject->hasModule<EventModule>())
        throw std::runtime_error("GameObject already has a EventModule!");
    if (!gameObject->hasModule<HitboxModule>())
        gameObject->addModule<HitboxModule>();
    if (gameObject->data.find("eventEffect") == gameObject->data.end())
        gameObject->data["eventEffect"] = NULL;
}

void EventModule::setEventEffect(GameObject *gameobject, std::function<void(GameObject *, GameObject *)> funk)
{
    gameobject->data["eventEffect"] = funk;
}
