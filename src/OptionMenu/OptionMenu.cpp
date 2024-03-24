/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** optionMenu
*/

#include "OptionMenu.hpp"
#include "button.hpp"
#include <GameMenu.hpp>
#include "Game.h"

OptionMenu::OptionMenu()
{
    if (!_optionFont.loadFromFile("assets/font/font.ttf"))
        throw Error("Failed to load font");
    //textOptionMenu();
    addButton("assets/OptionMenu/VolumeLow_button.png", (std::make_pair<float, float>)((float)game.getWindow().getSize().x / 2 - 150, (float)375), (std::make_pair<float, float>)((float)4, (float)4), Button::AUDIOLOW);
    addButton("assets/OptionMenu/VolumeUp_button.png", (std::make_pair<float, float>)((float)game.getWindow().getSize().x / 2 - 150, (float)375), (std::make_pair<float, float>)((float)4, (float)4), Button::AUDIOUP);
}

void OptionMenu::displayOptionMenu()
{

}

void OptionMenu::addButton(std::string path, std::pair<float, float> pos, std::pair<float, float> size, Button::ButtonType type)
{
    _buttons.push_back(new Button(path, pos, size, type));
}

void setupButton(std::vector<Button *> _buttons)
{
    _buttons = _buttons;
}
