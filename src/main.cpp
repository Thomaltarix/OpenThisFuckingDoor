/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** main
*/

#include "Game.hpp"

Game game;

int main(int argc, char **argv)
{
    int event;
    (void) argc;
    (void) argv;

    game.playMusic();
    while (game.isWindowOpen()) {
        event = game.getKeyEvent();
        game.clearWindow();
        game.DisplayWindow();
    }
    (void) event;
    return 0;
}