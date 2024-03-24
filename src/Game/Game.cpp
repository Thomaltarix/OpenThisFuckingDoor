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
    _scene = GAMEMENU;
    sf::FloatRect rect = sf::FloatRect(0, 0, 1920, 1080);
    _view = new sf::View(rect);
    game.getWindow().setView(*_view);
    _player = new Player("assets/character/player/idle/idle_1.png", std::pair<int, int>(500, 500), std::pair<int, int>(21, 13));
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
    static bool state = false;

    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::KeyPressed)
            for (auto& binds : _keyFunctions) {
                if (binds.first == _event.key.code)
                    binds.second();
            }
        if (_event.type == sf::Event::MouseButtonPressed) {
            state = true;
            handleMousePress();
        }
        if (_event.type == sf::Event::MouseButtonReleased) {
            state = false;
            handleMouseReleased();
        }
        if (_event.type == sf::Event::MouseMoved && state != true) {
            handleMouseOver();
        }
    }
    return -1;
}

void Game::handleMouseOver()
{
    sf::Vector2f mousePos = game.getWindow().mapPixelToCoords(sf::Mouse::getPosition(game.getWindow()));
    sf::IntRect rect;

    for (auto& button :game.getGameMenu()->getbutton()) {
        if (_scene == GAMEMENU) {
            if (button->getSprite()->getGlobalBounds().contains(mousePos)) {
                if (button->getType() == button->DOOR) {
                    rect = sf::IntRect(72,0,72,66);
                    button->getSprite()->setTextureRect(rect);
                } else {
                    rect = sf::IntRect(0,133,500,133);
                    button->getSprite()->setTextureRect(rect);
                }
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

void Game::handleMousePress()
{
    sf::Vector2f mousePos = game.getWindow().mapPixelToCoords(sf::Mouse::getPosition(game.getWindow()));
    sf::IntRect rect;

    for (auto& button :game.getGameMenu()->getbutton()) {
        if (button->getSprite()->getGlobalBounds().contains(mousePos)) {
            if (_scene == GAMEMENU) {
                if (button->getType() == button->DOOR) {
                    rect = sf::IntRect(144,0,72,66);
                    button->getSprite()->setTextureRect(rect);
                    rect = sf::IntRect(216,0,72,66);
                    button->getSprite()->setTextureRect(rect);
                } else {
                    rect = sf::IntRect(0,266,500,133);
                    button->getSprite()->setTextureRect(rect);
                }
                if (button->getType() == button->LEAVE) {
                    closeWindow();
                }
                if (button->getType() == button->DOOR) {
                    _scene = GAMEPLAY;
                }
            }
        }
    }
}

void Game::handleMouseReleased()
{
    sf::IntRect rect;

    for (auto& button :game.getGameMenu()->getbutton()) {
        if (_scene == GAMEMENU) {
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
