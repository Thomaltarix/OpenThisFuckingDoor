/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** Game
*/

#include "Game.hpp"
#include "button.hpp"

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

sf::RenderWindow &Game::getWindow()
{
    return _window;
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
            }/*
        if (_event.type == sf::Event::MouseButtonPressed) {
            handleMouseEvents(_event.mouseButton.button);
        }*/
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
/*
void handleMouseEvents(sf::Mouse::Button event)
{
    sf::Vector2f mousePos = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (_doorSprite.getGlobalBounds().contains(mousePos)) {

        } else if (_optionSprite.getGlobalBounds().contains(mousePos)) {

        } else if (_creditSprite.getGlobalBounds().contains(mousePos)) {

        } else if (_leaveSprite.getGlobalBounds().contains(mousePos)) {

        }
    }
}
*/