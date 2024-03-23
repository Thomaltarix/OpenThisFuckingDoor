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
    if (!_fontText.loadFromFile("assets/font/font.ttf"))
        throw Error("Failed to load font");
}

void Menu::TitleMenu(Game game)
{
    sf::Text title("OpenThisFuckingdoor", _fontText, 50);
    title.setFillColor(sf::Color::White);
    title.setStyle(sf::Text::Bold);
    title.setPosition((game.getWindow().getSize().x - title.getGlobalBounds().width) / 2, 50);
}

void Menu::DisplayMenu(Game *game, Button *button)
{
    game->getWindow().draw(button->GetDoorSprite());
    game->getWindow().draw(button->GetOptionSprite());
    game->getWindow().draw(button->GetCreditSprite());
    game->getWindow().draw(button->GetLeaveSprite());
}