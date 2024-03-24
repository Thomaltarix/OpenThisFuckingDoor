/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** No file there , just an epitech header example .
*/

#include "MovementModule.hpp"
#include "PositionModule.hpp"
#include "CollisionModule.hpp"
#include "HitboxModule.hpp"
#include <cmath>

MovementModule::MovementModule(GameObject *gameObject)
{
    if (gameObject->hasModule<MovementModule>())
        throw Error("GameObject already has a MovementModule!");
    if (!gameObject->hasModule<PositionModule>())
        gameObject->addModule<PositionModule>();
    if (gameObject->data.find("direction") == gameObject->data.end())
        gameObject->data["direction"] = Direction(IDLE);
    if (gameObject->data.find("speed") == gameObject->data.end())
        gameObject->data["speed"] = int(0);
}

void MovementModule::setDirection(GameObject *gameObject, Direction direction)
{
    gameObject->data["direction"] = direction;
}

void MovementModule::setSpeed(GameObject *gameObject, int speed)
{
    gameObject->data["speed"] = speed;
}

static bool checkAllColision(GameObject *gameObject, std::vector<GameObject*> gameObjects)
{
    if (!gameObject->hasModule<CollisionModule>())
        return false;
    for (auto other : gameObjects) {
        if (!other->hasModule<CollisionModule>())
            continue;
        if (HitboxModule::contact(gameObject, other)) {
            return true;
        }

    }
    return false;
}

void MovementModule::update(GameObject *gameObject, std::vector<GameObject*> gameObjects)
{
    (void) gameObjects;

    Direction dir = std::any_cast<Direction>(gameObject->data["direction"]);
    if (dir == IDLE)
        return;
    int y = std::any_cast<int>(gameObject->data["y"]);
    int x = std::any_cast<int>(gameObject->data["x"]);
    int speed = std::any_cast<int>(gameObject->data["speed"]);
    if (dir == UP)
        gameObject->data["y"] = y - speed;
    if (dir == DOWN)
        gameObject->data["y"] = y + speed;
    if (dir == LEFT)
        gameObject->data["x"] = x - speed;
    if (dir == RIGHT)
        gameObject->data["x"] = x + speed;
    if (checkAllColision(gameObject, gameObjects)) {
       gameObject->data["x"] = x;
       gameObject->data["y"] = y;
    }
}
