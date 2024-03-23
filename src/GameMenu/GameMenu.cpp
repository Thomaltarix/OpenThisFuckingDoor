/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** GameMenu
*/

#include "GameMenu.hpp"
#include "Game.hpp"
#include "button.hpp"
#include "Game.h"

GameMenu::GameMenu()
{
    if (!_fontText.loadFromFile("assets/font/font.ttf"))
        throw Error("Failed to load font");
    titleGameMenu();
    textGameMenu();
    addButton("assets/GameMenu/door_button.png", (std::make_pair<float, float>)((float)game.getWindow().getSize().x / 2 - 150, (float)375), (std::make_pair<float, float>)((float)4, (float)4), Button::DOOR);
    addButton("assets/GameMenu/option_button.png", (std::make_pair<float, float>)((float)game.getWindow().getSize().x / 2 - 190, (float)650), std::make_pair<float, float>((float)0.75, (float)0.75), Button::BUTTON);
    addButton("assets/GameMenu/credit_button.png", (std::make_pair<float, float>)((float)game.getWindow().getSize().x / 2 - 190, (float)775), std::make_pair<float, float>((float)0.75, (float)0.75), Button::BUTTON);
    addButton("assets/GameMenu/leave_button.png",(std::make_pair<float, float>)((float)game.getWindow().getSize().x / 2 - 190, (float)900), std::make_pair<float, float>((float)0.75, (float)0.75), Button::BUTTON);
}

void GameMenu::titleGameMenu()
{
    _textTitle.setFont(_fontText);
    _textTitle.setString("OpenThisFuckingDoor");
    _textTitle.setCharacterSize(100);
    _textTitle.setFillColor(sf::Color::Yellow);
    _textTitle.setStyle(sf::Text::Bold);
    _textTitle.setPosition((game.getWindow().getSize().x - _textTitle.getGlobalBounds().width) / 2, 50);
}

void GameMenu::textGameMenu()
{
    _textJouer.setFont(_fontText);
    _textJouer.setString("Open");
    _textJouer.setCharacterSize(75);
    _textJouer.setFillColor(sf::Color::Yellow);
    _textJouer.setStyle(sf::Text::Bold);
    _textJouer.setPosition((game.getWindow().getSize().x - _textJouer.getGlobalBounds().width) / 2 - 10, 270);
}

void GameMenu::displayGameMenu()
{
    game.getWindow().draw(_textTitle);
    game.getWindow().draw(_textJouer);
    for (auto& button : _buttons) {
        game.getWindow().draw(*(button->getSprite()));
    }
}

void GameMenu::addButton(std::string path, std::pair<float, float> pos, std::pair<float, float> size, Button::ButtonType type)
{
    _buttons.push_back(new Button(path, pos, size, type));
}

