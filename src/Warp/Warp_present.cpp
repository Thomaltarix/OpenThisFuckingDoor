/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** Warp_present
*/

#include "Warp_present.hpp"

Warp_present::Warp_present(std::string str, std::pair<int, int> pos, std::pair<int, int> size) : Warp(str, pos, size)
{
    (void) str;
    (void) pos;
    (void) size;
    data["Timeline"] = GameMap::PRESENT;
}