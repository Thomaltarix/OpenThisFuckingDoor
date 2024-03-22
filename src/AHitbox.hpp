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
    
    std::pair<float, float> getHitboxSize() {return (_hitboxSize);}
    void setHitboxSize(float x, float y) {_hitboxSize = std::pair<float, float>(x, y);}
    bool isTouched(AHitbox other);
protected:
    std::pair<float, float> _hitboxSize;
private:
};
