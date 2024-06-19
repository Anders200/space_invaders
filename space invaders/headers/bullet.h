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
    sf::FloatRect getGlobalBounds() const {
        return sf::RectangleShape::getGlobalBounds();
    }
private:
    bool isPlayerBullet;
};