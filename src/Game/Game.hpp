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

        // Getter
        sf::RenderWindow *getWindow() {return &_window;}

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

        std::unordered_map<sf::Keyboard::Key, std::function<void()>> _keyFunctions = {
            {sf::Keyboard::Escape, [this](){closeWindow();}}
        };
};

// Game game;
