/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** main
*/

#include "Game.hpp"

int main(int argc, char **argv)
{
    Game game;
    (void) argc;
    (void) argv;

    while (game.isWindowOpen()) {
        game.handleEvents();
        game.clearWindow();
        game.DisplayWindow();
    }
    return 0;
}