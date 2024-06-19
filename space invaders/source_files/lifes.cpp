#include "../headers/lifes.h"

lifes::lifes()
{
    setSize(sf::Vector2f(50.0f, 50.0f));
    setFillColor(sf::Color(29, 185, 84)); // Spotify green
    setOutlineColor(sf::Color(20, 130, 60)); // Darker green
    setOutlineThickness(1.0f);
}

lifes::~lifes()
{
    
}