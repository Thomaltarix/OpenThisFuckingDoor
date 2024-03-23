/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** No file there , just an epitech header example .
*/

#include "HitboxModule.hpp"
#include <cmath>

HitboxModule::HitboxModule(GameObject *gameObject)
{
    if (gameObject->hasModule<HitboxModule>())
        throw std::runtime_error("GameObject already has a HitboxModule!");
    if (gameObject->data.find("x") == gameObject->data.end())
        gameObject->data["x"] = double(0.0);
    if (gameObject->data.find("y") == gameObject->data.end())
        gameObject->data["y"] = double(0.0);
}

void HitboxModule::update(GameObject *gameObject, std::vector<GameObject*> gameObjects)
{
    for (auto otherObject : gameObjects) {
        if (gameObject != otherObject) {
            double distance = calculateDistance(gameObject, otherObject);
            if (distance < 10.0) { // Temporary threshold for collision detection
                std::cout << "Collision detected between objects!" << std::endl;
                // Handle what happens when collision is detected
            }
        }
    }
}

double HitboxModule::calculateDistance(GameObject *obj1, GameObject *obj2)
{
    double dx = std::any_cast<double>(obj1->data["x"]) - std::any_cast<double>(obj2->data["x"]);
    double dy = std::any_cast<double>(obj1->data["y"]) - std::any_cast<double>(obj2->data["y"]);

    return std::sqrt(dx * dx + dy * dy);
}