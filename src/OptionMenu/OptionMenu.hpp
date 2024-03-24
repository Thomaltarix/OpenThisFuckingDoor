/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** OptionMenu
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <functional>
#include "button.hpp"

class OptionMenu {
    public:
        OptionMenu();

        // title
        //void textOptionMenu();

        // display
        void displayOptionMenu();

        std::vector<Button *> getbutton() {return _buttons;}
        // button
        void addButton(std::string path, std::pair<float, float> pos, std::pair<float, float> size, Button::ButtonType type);
        void setupButton(std::vector<Button *> _buttons);
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
        sf::Font _optionFont;
        sf::Text _optionText;
        sf::Text _audioText;
        std::vector<Button *> _buttons;
};

