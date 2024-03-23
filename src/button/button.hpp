/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** button
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <functional>
#include "Game.hpp"

class Button {
    public:
        Button(Game *game);

        //button
        void DoorBouton(Game *game);
        void OptionButton(Game *game);
        void CreditButton(Game *game);
        void LeaveButton(Game *game);

        //getsprite
        sf::Sprite GetDoorSprite();
        sf::Sprite GetOptionSprite();
        sf::Sprite GetCreditSprite();
        sf::Sprite GetLeaveSprite();

        class Error : public std::exception {
            public:
                Error (const std::string &msg)
                {
                    _msg = msg;
                }

                const char *what() const noexcept override
                {
                    return _msg.c_str();
                }
            private:
                std::string _msg;
        };
    private:
        sf::Texture _doorTexture, _optionTexture, _creditTexture, _leaveTexture;
        sf::Sprite _doorSprite, _optionSprite, _creditSprite, _leaveSprite;
};