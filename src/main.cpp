/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** main
*/

#include "Game.hpp"

Game *getGame()
{
    static Game game;
    return &game;
}

int main(int argc, char **argv)
{
    Game *game = getGame();
    int event;
    (void) argc;
    (void) argv;

    game->playMusic();
    while (game->isWindowOpen()) {
        event = game->getKeyEvent();
        game->clearWindow();
        game->DisplayWindow();
    }
    (void) event;
    return 0;
}