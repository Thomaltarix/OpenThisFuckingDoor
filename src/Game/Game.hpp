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
#include "Player.hpp"

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
        void handleMouseEvents();

        // Getter
        sf::RenderWindow &getWindow() {return _window;}
        GameMenu *getGameMenu() {return _GameMenu;}
        Player *getPlayer() {return _player;}

        //Display
        void DisplayWindow();

        // View
        void setView(sf::View *view) {_view = view;}
        sf::View *getView(void) {return _view;}

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
        sf::View *_view;
        sf::Event _event;
        sf::Music _musicGame;
        GameMenu *_GameMenu;
        Player *_player;

        std::unordered_map<sf::Keyboard::Key, std::function<void()>> _keyFunctions = {
            {sf::Keyboard::Escape, [this](){closeWindow();}}
        };
};
