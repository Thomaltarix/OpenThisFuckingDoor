/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** Game
*/

#include "Game.hpp"
#include "button.hpp"
#include "Game.h"

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
    _GameMenu = new GameMenu();
    sf::FloatRect rect = sf::FloatRect(0, 0, 1920, 1080);
    _view = new sf::View(rect);
    game.getWindow().setView(*_view);
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
        if (_event.type == sf::Event::MouseMoved) {
            handleMouseEvents();
        }
    }
    return -1;
}

void Game::handleMouseEvents()
{
    sf::Vector2f mousePos = game.getWindow().mapPixelToCoords(sf::Mouse::getPosition(game.getWindow()));
    sf::IntRect rect;

    for (auto& button :game.getGameMenu()->getbutton()) {
        if (button->getSprite()->getGlobalBounds().contains(mousePos)) {
            if (button->getType() == button->DOOR) {
                rect = sf::IntRect(72,0,72,66);
                button->getSprite()->setTextureRect(rect);
            } else {
                rect = sf::IntRect(0,128,500,128);
                button->getSprite()->setTextureRect(rect);
            }
        } else {
            if (button->getType() == button->DOOR) {
                rect = sf::IntRect(0,0,72,66);
                button->getSprite()->setTextureRect(rect);
            } else {
                rect = sf::IntRect(0,0,500,128);
                button->getSprite()->setTextureRect(rect);
            }
        }
    }
}

void Game::DisplayWindow()
{
    _window.display();
}

void Game::playMusic()
{
    _musicGame.play();
}
