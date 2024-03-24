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
#include "../Ground/Ground.hpp"

GameMap::GameMap() {}

GameMap::~GameMap() {}

std::pair<Map, Map> GameMap::getMaps()
{
    return _maps;
}

void GameMap::setupMap(std::string path, MapType type)
{
    if (path.empty())
        return;
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

        GameObject *object = getGameObject(col, row, getPath(data["tilesets"], tile.get<int>()), type, data["tilesets"], tile.get<int>());
        list.push_back(object);
        col++;
    }
}

GameObject *GameMap::getGameObject(int x, int y, std::string path, MapType type, json tileSet, int tile)
{
    if (type == BACKGROUND) {
        return new Ground(path, std::pair<int, int>(x * 100, y * 100), std::pair<int, int>(100, 100));
    }
    std::string objectType = getObjectType(tileSet, tile);
    // Not implemented yet
    // if (objectType == "Player")
    //     return new Player(x, y, path);
    // if (objectType == "Wall")
    //     return new Wall(x, y, path);
    (void) x;
    (void) y;
    (void) path;
    (void) type;
    return new GameObject();
}

std::string GameMap::getPath(json tileSet, int tile)
{
    for (auto& tileData : tileSet) {
        if (tileData["firstgid"] == tile) {
            return "./assets/" + tileData["source"].get<std::string>();
        }
    }
    return "";
}

std::string GameMap::getObjectType(json tileSet, int tile)
{
    for (auto& tileData : tileSet) {
        if (tileData["firstgid"] == tile) {
            return tileData["type"].get<std::string>();
        }
    }
    return "";
}