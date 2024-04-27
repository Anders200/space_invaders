#include "../headers/player.h"

Player::Player() {
    setPosition(sf::Vector2f(400.0f, 700.0f));
    setSize(sf::Vector2f(50.0f, 50.0f));
    setFillColor(sf::Color::Blue);
    setOutlineColor(sf::Color::White);
    setOutlineThickness(1.0f);
    lifes = 3;
}
Player::~Player() {
    // Destroy player attributes
    // ...
}

void Player::move(char direction) {
    if(direction == 'l') {
        // Move player left
        setPosition(sf::Vector2f(getPosition().x - 5, getPosition().y));
    } else if(direction == 'r') {
        // Move player right
        setPosition(sf::Vector2f(getPosition().x + 5, getPosition().y));
    } else if(direction == 'n') {
        // Do nothing
    }
}

bullet* Player::shoot() {
    // Get the player's position
    sf::Vector2f position = this->getPosition();
    std::cout << "Player position: " << position.x << ", " << position.y << std::endl;

    // Create a new bullet at the player's position
    bullet* newBullet = new bullet(true, position);
    std::cout << newBullet << std::endl;
    return newBullet;
}
