#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


#include "player.h"
#include "bullet.h"

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
    sf::RectangleShape enemy;
    bullet* playerBullet;
    
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

    //Functions 
    void render();
};

#endif // GAME_H