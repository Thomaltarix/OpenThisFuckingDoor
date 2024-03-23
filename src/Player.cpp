/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** Player
*/

#include <HitboxModule.hpp>
#include <MovementModule.hpp>
#include "Player.hpp"

Player::Player()
{
    addModule<PlayerModule>();
}
