#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


//g++ src/main.cpp -lsfml-graphics -lsfml-window -lsfml-system


int main()
{
    //Window    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SPACE INVADERS");


    //Game Loop
    while (window.isOpen())
    {
        //Event polling
        sf::Event ev;
        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (ev.key.code == sf::Keyboard::Escape)
                    {
                        window.close();
                    }
                    break;
            }

        }
    //Update

    //Render

        window.clear(sf::Color::Cyan); //clear old frame

        //draw game here

        window.display(); 
    }

    return 0;
}
