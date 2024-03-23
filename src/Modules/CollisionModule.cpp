/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** No file there , just an epitech header example .
*/

#include "HitboxModule.hpp"
#include "CollisionModule.hpp"
#include <cmath>

CollisionModule::CollisionModule(GameObject *gameObject)
{
    if (!gameObject->hasModule<HitboxModule>())
        gameObject->addModule<HitboxModule>();
}

