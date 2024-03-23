/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** main
*/

#include "Game.hpp"
#include "Menu.hpp"
#include "button.hpp"

int main(int argc, char **argv)
{
    Game game;
    Menu menu(&game);
    Button button(&game);
    int event;
    (void) argc;
    (void) argv;

    game.playMusic();
    while (game.isWindowOpen()) {
        event = game.getKeyEvent();
        game.clearWindow();
        menu.DisplayMenu(&game, &button);
        game.DisplayWindow();
    }
    (void) event;
    return 0;
}