/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** IEntity
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>

class AEntity {
    public:
        AEntity();
        ~AEntity();

        // Setters
        void setPos(float x, float y) {_pos = std::pair<float, float>(x, y);}
        void setSize(float x, float y) {_size = std::pair<float, float>(x, y);}
        void setTextures(std::vector<std::string> strings);

        // Getters
        std::pair<float, float> getPos() const {return _pos;}
        std::pair<float, float> getSize() const {return _size;}
        std::vector<sf::Texture> getTextures() const {return _textures;}
    protected:
        class Error : public std::exception {
            public:
                Error (const std::string &msg)
                {
                    _msg = msg;
                }

                const char *what() const noexcept override
                {
                    return _msg.c_str();
                }
            private:
                std::string _msg;
        };
        std::pair<float, float> _pos;
        std::pair<float, float> _size;
        std::vector<sf::Texture> _textures;
    private:
};
