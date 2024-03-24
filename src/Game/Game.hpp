/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** Game
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <functional>
#include "../GameMenu/GameMenu.hpp"
#include "OptionMenu.hpp"

enum Scene {
    GAMEMENU,
    OPTION,
    CREDIT,
    GAMEPLAY,
};

class Game {
    public:
        Game();
        ~Game();

        //Window
        bool isWindowOpen() const;
        void closeWindow();
        void clearWindow();

        //Events
        int getKeyEvent();
        void handleEvents();
        void handleMouseOver();
        void handleMousePress();
        void handleMouseReleased();

        // Getter
        sf::RenderWindow &getWindow() {return _window;}
        GameMenu *getGameMenu() {return _GameMenu;}
        enum Scene getScene() {return _scene;}
        OptionMenu *getOptionMenu() {return _OptionMenu;}

        //Display
        void DisplayWindow();

        //Music
        void playMusic();

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
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Music _musicGame;
        GameMenu *_GameMenu;
        OptionMenu *_OptionMenu;
        enum Scene _scene;

        std::unordered_map<sf::Keyboard::Key, std::function<void()>> _keyFunctions = {
        };
};
