#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <SFML/Graphics.hpp>
#include "bullet.h"

class Player : public sf::RectangleShape
{
public:
    Player();
    ~Player();
    void move(char direction);
    bullet* shoot();

private:
    int lifes;
    int score;

};

#endif