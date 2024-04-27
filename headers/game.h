#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


#include "player.h"
#include "bullet.h"
#include "enemy.h"

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    //variables
    //window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    //game objects
    Player player;
    bullet* playerBullet;
    enum class Direction { None, Left, Right };
    Direction playerDirectionA = Direction::None;
    Direction playerDirectionD = Direction::None;
    Enemy*** enemies;
    std::vector <bullet*> enemyBullets;


    int const leftBound = 100;
    int const rightBound = 900;
    //private functions

    void initVariables();
    void initWindow();
    void initPlayer();
    void initEnemies();
    void fireBullet();
public:
    //Constructor //Destructor
    Game();
    virtual ~Game();


    //Accessors
    const bool running() const;
    void pollEvent();
    void update();
    void updateEnemyBullets();

    //Functions 
    void render();
    void addEnemyBullet(bullet* b);
    void removeEnemyBullet(bullet* b);
};

#endif // GAME_H