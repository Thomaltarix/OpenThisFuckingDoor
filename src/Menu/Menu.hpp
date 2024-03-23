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
        void titleMenu(Game *game);
        void textMenu(Game *game);
        // Display menu
        void displayMenu(Game *game);

        void addButton(std::string path, std::pair<float, float> pos, std::pair<float, float> size, Button::ButtonType type);
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
        std::vector<Button *> _buttons;
};