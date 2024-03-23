/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** Player
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <unordered_map>
#include <AEntity.hpp>

class Player {
    public:
        Player() = default;
        ~Player() = default;

    protected:
        std::unordered_map<std::string, AEntity> _totems;
    private:
};
