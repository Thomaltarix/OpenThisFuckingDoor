/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** Warp_present
*/

#pragma once

#include <Warp.hpp>

class Warp_present : public Warp {
    public:
        Warp_present(std::string str, std::pair<int, int> pos, std::pair<int, int> size);
        ~Warp_present() = default;

        sf::Texture getTexture(void) {return std::any_cast<sf::Texture>(data["texture"]);}
        std::pair<int, int> getPos(void) {return std::pair<int, int>(std::any_cast<int>(data["x"]), std::any_cast<int>(data["y"]));}
        std::pair<int, int> getSize(void) {return std::any_cast<std::pair<int, int>>(data["TextureSize"]);}
    protected:
    private:
};