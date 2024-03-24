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

void displayMap(Map map)
{
    std::vector<GameObject *> vec;
    for (auto &elem1 : map) {
        for (auto &elem2 : elem1) {
            vec.push_back(elem2);
            elem2->update(vec);
            vec.clear();
        }
    }
}

template<typename T>
static std::vector<T*> tab2vector(std::vector<std::vector<T*>> tab)
{
    std::vector<T*> vector;

    for (auto elem : tab) {
        for (auto elem2 : elem) {
            vector.push_back(elem2);
        }
    }
    return vector;
}

static void doubleCheck(std::vector<GameObject *> vector)
{
    for (auto elem : vector) {
        if (elem->data.find("x") == elem->data.end())
            elem->data["x"] = 0;
        if (elem->data.find("y") == elem->data.end())
            elem->data["y"] = 0;
        if (elem->data.find("direction") == elem->data.end())
            elem->data["direction"] = IDLE;
        if (elem->data.find("direction") == elem->data.end())
            elem->data["size"] = std::pair<int, int>(0, 0);
    }
}

int main(int argc, char **argv)
{
    int event;
    (void) argc;
    (void) argv;

    game.playMusic();
    game.setTimeLine(GameMap::TimeLine::PRESENT);

    std::vector<GameObject *> vecpr;
    vecpr = tab2vector<GameObject>(game.getGameMap()->getMap(GameMap::TimeLine::PRESENT).second);
    vecpr.push_back(game.getPlayer());
    doubleCheck(tab2vector<GameObject>(game.getGameMap()->getMap(GameMap::TimeLine::PRESENT).second));

    std::vector<GameObject *> vecpa;
    vecpa = tab2vector<GameObject>(game.getGameMap()->getMap(GameMap::TimeLine::PAST).second);
    vecpa.push_back(game.getPlayer());
    doubleCheck(tab2vector<GameObject>(game.getGameMap()->getMap(GameMap::TimeLine::PAST).second));

    std::vector<GameObject *> vecf;
    vecf = tab2vector<GameObject>(game.getGameMap()->getMap(GameMap::TimeLine::FUTUR).second);
    vecf.push_back(game.getPlayer());
    doubleCheck(tab2vector<GameObject>(game.getGameMap()->getMap(GameMap::TimeLine::FUTUR).second));

    while (game.isWindowOpen()) {
        event = game.getKeyEvent();
        game.clearWindow();
        if (game.getScene() == GAMEMENU)
            game.getGameMenu()->displayGameMenu();
        if (game.getScene() == OPTION)
            game.getOptionMenu()->displayOptionMenu();
        if (game.getScene() == GAMEPLAY) {
            displayMap(game.getGameMap()->getMap(game.getTimeLine()).first);
            displayMap(game.getGameMap()->getMap(game.getTimeLine()).second);
            game.getPlayer()->update(game.getTimeLine() == GameMap::TimeLine::PRESENT ? vecpr : game.getTimeLine() == GameMap::TimeLine::PAST ? vecpa : vecf);
            game.getPlayer()->displayPlayer();
        }
        if (game.getScene() == CREDIT)
            game.getCreditMenu()->displayCredit();
        game.DisplayWindow();
    }
    (void) event;
    return 0;
}