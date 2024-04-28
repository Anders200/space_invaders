#ifndef ENEMY_H
#define ENEMY_H


#include <iostream>
#include <SFML/Graphics.hpp>
#include "bullet.h"

enum class Type { chonker, bonker, donker, dead};
const int scores[] = {10, 20, 50, 0};

class Enemy : public sf::RectangleShape
{
public:
    Enemy(Type type, sf::Vector2f position);
    
    ~Enemy();
    void move();
    bullet* shoot();
    void setType(Type type);
    void setSpeed(float speed);
    float getSpeed();
private:
    float enemySpeed;
    Type type;
    int score;
    float shootingChance;
};
#endif