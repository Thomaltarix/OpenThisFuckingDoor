/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** Warp_past
*/

#include "Warp_past.hpp"

Warp_past::Warp_past(std::string str, std::pair<int, int> pos, std::pair<int, int> size) : Warp(str, pos, size)
{
    (void) str;
    (void) pos;
    (void) size;
    data["Timeline"] = GameMap::PAST;
}