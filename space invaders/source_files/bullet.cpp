#include "../headers/bullet.h"

#include <iostream> 

bullet::bullet(bool isPlayerBullet, sf::Vector2f position)
{
    setPosition(position.x + 22.5, position.y + 25);
    setSize(sf::Vector2f(5.0f, 10.0f));
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(1.0f);
    if(isPlayerBullet) {
        setFillColor(sf::Color::Yellow);
    } else {
        setFillColor(sf::Color(255, 165, 0)); 
    }
}


bullet::~bullet()
{
   
}
void bullet::move(float speed) {
    setPosition(sf::Vector2f(getPosition().x, getPosition().y - speed));
    }