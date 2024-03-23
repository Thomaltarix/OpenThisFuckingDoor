/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** No file there , just an epitech header example .
*/

#pragma once

#include "../Game/GameObject.hpp"

class MovementModule : public Module {
public:
    MovementModule(GameObject *gameObject);
    ~MovementModule() = default;

    void setDirection(double x, double y);

    void update(GameObject *gameObject, std::vector<GameObject*> gameObjects) override;

private:
    double directionX; // Movement direction along X-axis
    double directionY; // Movement direction along Y-axis
};
