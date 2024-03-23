/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** menu
*/

#include "Menu.hpp"
#include "Game.hpp"
#include "button.hpp"

Menu::Menu(Game *game)
{
    if (!_fontText.loadFromFile("assets/font/font.ttf"))
        throw Error("Failed to load font");
    TitleMenu(game);
    TextMenu(game);
}

void Menu::TitleMenu(Game *game)
{
    _textTitle.setFont(_fontText);
    _textTitle.setString("OpenThisFuckingDoor");
    _textTitle.setCharacterSize(100);
    _textTitle.setFillColor(sf::Color::Yellow);
    _textTitle.setStyle(sf::Text::Bold);
    _textTitle.setPosition((game->getWindow().getSize().x - _textTitle.getGlobalBounds().width) / 2, 50);
}

void Menu::TextMenu(Game *game)
{
    _textJouer.setFont(_fontText);
    _textJouer.setString("Open");
    _textJouer.setCharacterSize(75);
    _textJouer.setFillColor(sf::Color::Yellow);
    _textJouer.setStyle(sf::Text::Bold);
    _textJouer.setPosition((game->getWindow().getSize().x - _textJouer.getGlobalBounds().width) / 2 - 10, 270);
}

void Menu::DisplayMenu(Game *game, Button *button)
{
    game->getWindow().draw(_textTitle);
    game->getWindow().draw(_textJouer);
    game->getWindow().draw(button->GetDoorSprite());
    game->getWindow().draw(button->GetOptionSprite());
    game->getWindow().draw(button->GetCreditSprite());
    game->getWindow().draw(button->GetLeaveSprite());
}