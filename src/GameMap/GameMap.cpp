/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** GameMap
*/

#include "GameMap.hpp"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <fstream>

GameMap::GameMap() {}

GameMap::~GameMap() {}

std::tuple<Map, Map> GameMap::getMaps()
{
    return _maps;
}

void GameMap::fillMapFromJson(std::string path, MapType type)
{
    std::ifstream f(path.c_str());
    json data = json::parse(f);

    int row = 0;
    int col = 0;
    std::vector<GameObject *> list;

    for (auto& tile : data["layers"][0]["data"]) {
        if (col == data["height"]) {
            col = 0;
            row++;
            if (type == BACKGROUND)
                _maps.first.push_back(list);
            if (type == HITBOX)
                _maps.second.push_back(list);
            list.clear();
        }
        if (row == data["width"])
            return;
        GameObject *object = getGameObject(col, row, getPath(data["tilesets"], tile.get<int>()), type);
        list.push_back(object);
        col++;
    }
}

GameObject *GameMap::getGameObject(int x, int y, std::string path, MapType type)
{
    (void) x;
    (void) y;
    (void) path;
    (void) type;
    GameObject *object = new GameObject();
    return object;
}

std::string GameMap::getPath(json tileSet, int tile)
{
    for (auto& tileData : tileSet) {
        if (tileData["firstgid"] == tile) {
            return "./assets/" + tileData["image"].get<std::string>();
        }
    }
    return "";
}
