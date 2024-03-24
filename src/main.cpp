/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** main
*/

#include "GameMenu/GameMenu.hpp"
#include "Game.hpp"
#include "button.hpp"

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
        if (game.getScene() == GAMEMENU) {
            game.getGameMenu()->displayGameMenu();
        }
        if (game.getScene() == OPTION) {
            game.getOptionMenu()->displayOptionMenu();
        }
        game.DisplayWindow();
    }
    (void) event;
    return 0;
}