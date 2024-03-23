/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** No file there , just an epitech header example .
*/

#include "MovementModule.hpp"
#include <cmath>

MovementModule::MovementModule(GameObject *gameObject) : directionX(0.0), directionY(0.0)
{
    if (gameObject->hasModule<MovementModule>())
        throw std::runtime_error("GameObject already has a MovementModule!");
    if (gameObject->data.find("x") == gameObject->data.end())
        gameObject->data["x"] = double(0.0);
    if (gameObject->data.find("y") == gameObject->data.end())
        gameObject->data["y"] = double(0.0);
}

void MovementModule::setDirection(double x, double y)
{
    directionX = x;
    directionY = y;
}

void MovementModule::update(GameObject *gameObject, std::vector<GameObject*> gameObjects)
{
    (void) gameObjects;
    double distance = std::sqrt(directionX * directionX + directionY * directionY);

    if (distance > 1.0) { // Move only if sufficiently far away from target
        double angle = std::atan2(directionY, directionX);
        gameObject->data["x"] = std::any_cast<double>(gameObject->data["x"]) + std::cos(angle);
        gameObject->data["y"] = std::any_cast<double>(gameObject->data["y"]) + std::sin(angle);
        std::cout << "Moving GameObject..." << std::endl;
    }
}