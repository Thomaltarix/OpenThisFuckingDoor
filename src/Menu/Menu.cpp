/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** menu
*/

#include "Menu.hpp"
#include "Game.hpp"
#include "button.hpp"

Menu::Menu()
{
    Game *game = getGame();
    if (!_fontText.loadFromFile("assets/font/font.ttf"))
        throw Error("Failed to load font");
    titleMenu();
    textMenu();
    addButton("assets/menu/door_button.png", (std::make_pair<float, float>)((float)game->getWindow().getSize().x / 2 - 180, (float)375), (std::make_pair<float, float>)((float)4, (float)4), Button::DOOR);
    addButton("assets/menu/option_button.png", (std::make_pair<float, float>)((float)game->getWindow().getSize().x / 2 - 190, (float)650), std::make_pair<float, float>((float)0.75, (float)0.75), Button::BUTTON);
    addButton("assets/menu/credit_button.png", (std::make_pair<float, float>)((float)game->getWindow().getSize().x / 2 - 190, (float)775), std::make_pair<float, float>((float)0.75, (float)0.75), Button::BUTTON);
    addButton("assets/menu/leave_button.png",(std::make_pair<float, float>)((float)game->getWindow().getSize().x / 2 - 190, (float)900), std::make_pair<float, float>((float)0.75, (float)0.75), Button::BUTTON);
}

void Menu::titleMenu()
{
    Game *game = getGame();

    _textTitle.setFont(_fontText);
    _textTitle.setString("OpenThisFuckingDoor");
    _textTitle.setCharacterSize(100);
    _textTitle.setFillColor(sf::Color::Yellow);
    _textTitle.setStyle(sf::Text::Bold);
    _textTitle.setPosition((game->getWindow().getSize().x - _textTitle.getGlobalBounds().width) / 2, 50);
}

void Menu::textMenu()
{
    Game *game = getGame();

    _textJouer.setFont(_fontText);
    _textJouer.setString("Open");
    _textJouer.setCharacterSize(75);
    _textJouer.setFillColor(sf::Color::Yellow);
    _textJouer.setStyle(sf::Text::Bold);
    _textJouer.setPosition((game->getWindow().getSize().x - _textJouer.getGlobalBounds().width) / 2 - 10, 270);
}

void Menu::displayMenu()
{
    Game *game = getGame();

    game->getWindow().draw(_textTitle);
    game->getWindow().draw(_textJouer);
    for (auto& button : _buttons) {
        game->getWindow().draw(button->getSprite());
    }
}

void Menu::addButton(std::string path, std::pair<float, float> pos, std::pair<float, float> size, Button::ButtonType type)
{
    _buttons.push_back(new Button(path, pos, size, type));
}