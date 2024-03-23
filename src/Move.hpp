/*
** EPITECH PROJECT, 2024
** OpenThisFuckingDoor
** File description:
** Move
*/

#pragma once

class Move : public Hitbox {
    public:
        Move() = default;
        ~Move() = default;

        // Setters
        void setSpeed(float speed) {_speed = speed;}

        // Getters
        float getSpeeed() {return _speed;}
    protected:
        float _speed;
    private:
};
