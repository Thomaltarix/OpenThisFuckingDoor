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
#include <unordered_map>

class AEntity {
    public:
        AEntity() = default;
        ~AEntity() = default;

        // Enum
        enum State {
            IDLE = 0,
            IDLE2,
            IDLE3,
            IDLE4,
            IDLE5,
            IDLE6,
            UP,
            UP2,
            UP3,
            UP4,
            UP5,
            UP6,
            DOWN,
            DOWN2,
            DOWN3,
            DOWN4,
            DOWN5,
            DOWN6,
            RIGHT,
            RIGHT2,
            RIGHT3,
            RIGHT4,
            RIGHT5,
            RIGHT6,
            LEFT,
            LEFT2,
            LEFT3,
            LEFT4,
            LEFT5,
            LEFT6
        };

        // Setters
        void setPos(float x, float y) {_pos = std::pair<float, float>(x, y);}
        void setSize(float x, float y) {_size = std::pair<float, float>(x, y);}
        void setTextures(std::vector<std::string> strings);

        // Getters
        std::pair<float, float> getPos() const {return _pos;}
        std::pair<float, float> getSize() const {return _size;}

        void display(sf::RenderWindow window, enum State);

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
    protected:
        std::pair<float, float> _pos;
        std::pair<float, float> _size;
        std::unordered_map<std::string, sf::Texture> _textures;
    private:
};
