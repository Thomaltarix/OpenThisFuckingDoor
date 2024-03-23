/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** hitbox
*/

#include "AHitbox.hpp"

AHitbox::AHitbox(float x, float y)
{
    _hitboxSize = std::pair<float,float>(x, y);
}

std::pair<float, float> AHitbox::getHitboxPos()
{
    std::pair<float, float> E_pos = getPos();
    std::pair<float, float> E_size = getSize();
    std::pair<float, float> H_size = getSize();
    std::pair<float, float> H_pos;

    H_pos = std::pair<float,float>(E_pos.first + ((E_size.first - H_size.first) / 2), E_pos.second + ((E_size.second - H_size.second) / 2));
    return (H_pos);
}

bool AHitbox::isTouched(AHitbox &other)
{
    std::pair<float, float> my_pos = getHitboxPos();
    std::pair<float, float> other_pos = other.getHitboxPos();
    std::pair<float, float> my_size = _hitboxSize;
    std::pair<float, float> other_size = other._hitboxSize;

    if (other_pos.first >= my_pos.first + my_size.first && other_pos.first + other_size.first <= my_pos.first && other_pos.second >= my_pos.second + my_size.second && other_size.second + other_size.second <= my_pos.second){
        return (false);
    }
    return (true);
}
