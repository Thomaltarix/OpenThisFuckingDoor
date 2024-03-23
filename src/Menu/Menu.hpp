/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** menu
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <functional>
#include "Game.hpp"
#include "button.hpp"

class Menu {
    public:
        Menu(Game *game);

        // title
        void TitleMenu(Game *game);
        void TextMenu(Game *game);
        // Display menu
        void DisplayMenu(Game *game, Button *button);

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
        sf::Font _fontText;
        sf::Text _textJouer;
        sf::Text _textTitle;
};