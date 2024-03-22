/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
    _window.create(sf::VideoMode(1920, 1080), "OpenThisFuckingDoor", sf::Style::Close | sf::Style::Fullscreen);
    _window.setFramerateLimit(60);
    if (!isWindowOpen())
        throw Error("Failed to create window");
    _event = sf::Event();
    if (!_musicGame.openFromFile("assets/music/music_gameplay.wav"))
        throw Error("Failed to load Music");
    _musicGame.setLoop(true);
}

Game::~Game()
{
    closeWindow();
}

bool Game::isWindowOpen() const
{
    return _window.isOpen();
}

void Game::closeWindow()
{
    _window.close();
    if (isWindowOpen())
        throw Error("Failed to close window");
}

void Game::clearWindow()
{
    _window.clear();
}

int Game::getKeyEvent()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            closeWindow();
        if (_event.type == sf::Event::KeyPressed)
            for (auto& binds : _keyFunctions) {
                if (binds.first == _event.key.code)
                    binds.second();
            }
    }
    return -1;
}

void Game::DisplayWindow()
{
    _window.display();
}

void Game::playMusic()
{
    _musicGame.play();
}