/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** button
*/

#include "button.hpp"

Button::Button(Game *game)
{
    if (!_doorTexture.loadFromFile("assets/menu/door_button.png") ||
        !_optionTexture.loadFromFile("assets/menu/option_button.png") ||
        !_creditTexture.loadFromFile("assets/menu/credit_button.png") ||
        !_leaveTexture.loadFromFile("assets/menu/leave_button.png"))
        throw Error("Failed to load image");
    _doorSprite.setTexture(_doorTexture);
    _optionSprite.setTexture(_optionTexture);
    _creditSprite.setTexture(_creditTexture);
    _leaveSprite.setTexture(_leaveTexture);
    DoorBouton(game);
    OptionButton(game);
    CreditButton(game);
    LeaveButton(game);
}

void Button::DoorBouton(Game *game)
{
    
    _doorSprite.setTextureRect(sf::IntRect(0,0,80,66));
    _doorSprite.scale(4, 4);
    _doorSprite.setPosition(game->getWindow().getSize().x / 2 - 180, 375);
}

void Button::OptionButton(Game *game)
{
    _optionSprite.setTextureRect(sf::IntRect(0,0,500,150));
    _optionSprite.scale(0.75, 0.75);
    _optionSprite.setPosition(game->getWindow().getSize().x / 2 - 190, 650);
}

void Button::CreditButton(Game *game)
{
    _creditSprite.setTextureRect(sf::IntRect(0,0,500,150));
    _creditSprite.scale(0.75, 0.75);
    _creditSprite.setPosition(game->getWindow().getSize().x / 2 - 190, 775);
}

void Button::LeaveButton(Game *game)
{
    _leaveSprite.setTextureRect(sf::IntRect(0,0,500,150));
    _leaveSprite.scale(0.75, 0.75);
    _leaveSprite.setPosition(game->getWindow().getSize().x / 2 - 190, 900);
}

sf::Sprite Button::GetDoorSprite()
{
    return _doorSprite;
}

sf::Sprite Button::GetOptionSprite()
{
    return _optionSprite;
}

sf::Sprite Button::GetCreditSprite()
{
    return _creditSprite;
}

sf::Sprite Button::GetLeaveSprite()
{
    return _leaveSprite;
}
