/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** Move
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

class Move : public Hitbox {
    public:
        Move() = default;
        ~Move() = default;

        // Setters
        void setSpeed(float speed) {_speed = speed;}

        // Getters
        float getSpeeed() {return _speed;}

        // Move metho
        void moveRight(void);
        void moveLeft(void);
        void moveUp(void);
        void moveDown(void);
    protected:
        float _speed;
    private:
};
