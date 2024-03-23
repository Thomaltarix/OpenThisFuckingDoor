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
        enum ButtonType {
            DOOR,
            BUTTON,
        };

        Button(std::string path, std::pair<float, float> pos, std::pair<float, float> size, ButtonType type);

        sf::Sprite getSprite() { return _sprite;}

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
        sf::Texture _texture;
        std::pair<float, float> _pos;
        std::pair<float, float> _size;
        sf::Sprite _sprite;
};