/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** No file there , just an epitech header example .
*/

#pragma once

#include "../Game/GameObject.hpp"

class HitboxModule : public Module {
public:
    HitboxModule(GameObject *gameObject);
    ~HitboxModule() = default;

    void update(GameObject *gameObject, std::vector<GameObject*> gameObjects) override;
private:
    double calculateDistance(GameObject *obj1, GameObject *obj2);
};
