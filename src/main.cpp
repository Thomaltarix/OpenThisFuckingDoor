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
    int event;
    (void) argc;
    (void) argv;
    (void) event;
    while (game.isWindowOpen()) {
        event = game.getKeyEvent();
        game.clearWindow();
        game.DisplayWindow();
    }
    return 0;
}