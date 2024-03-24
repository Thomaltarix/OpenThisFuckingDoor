/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** Warp_futur
*/

#include "Warp_futur.hpp"

Warp_futur::Warp_futur(std::string str, std::pair<int, int> pos, std::pair<int, int> size) : Warp(str, pos, size)
{
    (void) str;
    (void) pos;
    (void) size;
    data["Timeline"] = GameMap::FUTUR;
}