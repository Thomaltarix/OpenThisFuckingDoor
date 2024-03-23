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

DisplayModule::DisplayModule(GameObject *gameObject)
{
    if (gameObject->hasModule<DisplayModule>())
        throw std::runtime_error("GameObject already has a DisplayModule!");
    if (gameObject->data.find("texture") == gameObject->data.end())
        gameObject->data["texture"] = nullptr;
    if (gameObject->data.find("TextureSize") == gameObject->data.end())
        gameObject->data["TextureSize"] = std::pair<int, int>(0, 0);
    if (gameObject->hasModule<TimeModule>() == false)
        gameObject->addModule<TimeModule>();
}

void DisplayModule::update(GameObject *gameObject, std::vector<GameObject*> gameObjects)
{
    sf::Sprite sprite;
    std::vector<sf::Texture> textures = std::any_cast<std::vector<sf::Texture>>(gameObject->data["texture"]);

    sprite.setTexture(textures[std::any_cast<Direction>(gameObject->data["direction"])], false);
    sprite.setPosition((sf::Vector2f){std::any_cast<float>(gameObject->data["x"]), std::any_cast<float>(gameObject->data["y"])});
    game.getWindow()->draw(sprite);
}