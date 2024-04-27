#include "../headers/bullet.h"
#include "../headers/enemy.h"


Enemy::Enemy(Type type, sf::Vector2f position)
{
    setPosition(position.x, position.y);
    setSize(sf::Vector2f(40.0f, 40.0f));
    setOutlineColor(sf::Color::White);
    setOutlineThickness(1.0f);
    setType(type);


    switch (type)
    {
    case Type::chonker:
        setFillColor(sf::Color(255, 0, 0));
        score = scores[0];
        shootingChance = 0.005f;
        break;
    case Type::bonker:
        setFillColor(sf::Color(127, 0, 0));
        score = scores[1];
        shootingChance = 0.002f;
        break;
    case Type::donker:
        setFillColor(sf::Color(255, 127, 127));
        score = scores[2];
        shootingChance = 0.001f;
        break;
    }
}

Enemy::~Enemy()
{

}

//functions
void Enemy::move()
{
    // Move the enemy
    setPosition(getPosition().x + 1, getPosition().y);
}
void Enemy::setType(Type type) {
    this->type = type;
}