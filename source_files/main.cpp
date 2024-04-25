#include <iostream>
#include "../headers/game.h"


//g++ source_files/main.cpp source_files/game.cpp -lsfml-graphics -lsfml-window -lsfml-system


int main()
{
    //Init game engine
    Game game;

    //Game Loop
    while (game.running())
    {
        //Update
        game.update();
        //Render
        game.render();
    }
    return 0;
}
