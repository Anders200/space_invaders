#ifndef BULLET_H
#define BULLET_H

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class bullet : public sf::RectangleShape
{
public:
    bullet(bool isPlayerBullet, sf::Vector2f position);
    ~bullet();
    void move(float speed);
    bool getIsPlayerBullet() { return isPlayerBullet; }
private:
    bool isPlayerBullet;
};

#endif