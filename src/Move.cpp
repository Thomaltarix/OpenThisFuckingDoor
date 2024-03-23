/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** Move
*/

#include "Move.hpp"

void Move::moveDown(void)
{
    _pos.second += _speed;
}

void Move::moveUp(void)
{
    _pos.second -= _speed;
}

void Move::moveRight(void)
{
    _pos.first += _speed;
}

void Move::moveLeft(void)
{
    _pos.first -= _speed;
}
