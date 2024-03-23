/*
** EPITECH PROJECT, 2024
** OpenthisFuckinDoor
** File description:
** AHitbox
*/

#include "AEntity.hpp"

class AHitbox:public AEntity
{
public:
    AHitbox(float x, float y);
    ~AHitbox() = default;
    
    void setSize(float x, float y) {_hitboxSize = std::pair<float, float>(x, y);}
    bool isTouched(AHitbox &other);
    std::pair<float, float> getHitboxPos();
protected:
    std::pair<float, float> _hitboxSize;
private:
};
