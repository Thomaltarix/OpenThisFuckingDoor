/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** DisplayModule
*/

#include <Game.hpp>
#include <SFML/Graphics.h>
#include <TimeModule.hpp>
#include <MovementModule.hpp>
#include "DisplayModule.hpp"
#include <RotatableModule.hpp>
#include <Game.h>
#include <cstring>

DisplayModule::DisplayModule(GameObject *gameObject)
{
    if (gameObject->hasModule<DisplayModule>())
        throw Error("GameObject already has a DisplayModule!");
    if (gameObject->data.find("texture") == gameObject->data.end())
        gameObject->data["texture"] = nullptr;
    if (gameObject->data.find("TextureSize") == gameObject->data.end())
        gameObject->data["TextureSize"] = std::pair<int, int>(0, 0);
    if (gameObject->hasModule<TimeModule>() == false)
        gameObject->addModule<TimeModule>();
}

std::string getDir(void)
{
    enum Direction dir = std::any_cast<enum Direction>(game.getPlayer()->data["direction"]);

    if (dir == UP)
        return ("walk_back/walk_back_");
    if (dir == DOWN)
        return ("walk_front/walk_front_");
    if (dir == RIGHT)
        return ("walk_right/walk_right_");
    if (dir == LEFT)
        return ("walk_left/walk_left_");
    return ("idle/idle_");
}

std::string animation(void)
{
    double elapse = (double)std::any_cast<sf::Clock*>(game.getPlayer()->data["clock"])->getElapsedTime().asSeconds();
    std::string path = "assets/character/player/" + getDir();

    if (elapse >= 0 && elapse < 0.1)
        return (path + "1.png");
    if (elapse >= 0.1 && elapse < 0.2)
        return (path + "2.png");
    if (elapse >= 0.2 && elapse < 0.3)
        return (path + "3.png");
    if (elapse >= 0.3 && elapse < 0.4)
        return (path + "4.png");
    if (elapse >= 0.4 && elapse < 0.5)
        return (path + "5.png");
    if (elapse >= 0.5 && elapse < 0.6)
        return (path + "6.png");
    std::any_cast<sf::Clock*>(game.getPlayer()->data["clock"])->restart();
    return (path + "1.png");
}

void DisplayModule::update(GameObject *gameObject, std::vector<GameObject*> gameObjects)
{
    sf::Sprite sprite;
    std::string textures = std::any_cast<std::string>(gameObject->data["texture"]);
    sf::Texture tex;

    tex.loadFromFile(textures);
    (void) gameObjects;
    if (gameObject->hasModule<PlayerModule>()) {
        tex.loadFromFile(animation());
        sprite.setTexture(tex, false);
    } else
        sprite.setTexture(tex, false);
    sprite.setPosition((sf::Vector2f){(float)std::any_cast<int>(gameObject->data["x"]), (float)std::any_cast<int>(gameObject->data["y"])});
    game.getWindow().draw(sprite);
}