#pragma once

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    
/*
class that acts as the game engine
*/

public:
    //Constructor //Destructor
    Game();
    virtual ~Game();

    //Functions

    void update();
    void render();
};

#endif // GAME_H