#include "../headers/game.h"
//private functions
void Game::initVariables()
{
    this->window = nullptr;
    
}
void Game::initWindow()
{
    this -> videoMode = sf::VideoMode(800, 600);
    this->window = new sf::RenderWindow(this->videoMode, "SPACE INVADERS", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
    
}
void Game::initPlayer()
{
    Player player;
}

void Game::initEnemies() {
    this->enemy.setPosition(sf::Vector2f(100.0f, 100.0f));
    this->enemy.setSize(sf::Vector2f(50.0f, 50.0f));
    this->enemy.setFillColor(sf::Color::Red);
    this->enemy.setOutlineColor(sf::Color::Black);
    this->enemy.setOutlineThickness(1.0f);
}
void Game::fireBullet() {
    // Only create a new bullet if there isn't one already
    playerBullet = player.shoot();
    std::cout << "Firing bullet" << std::endl;
    std::cout << "Player bullet: " << &playerBullet << std::endl;
    if (playerBullet != nullptr) {
        if (playerBullet->getIsPlayerBullet()) {
            std::cout << "Moving player bullet" << std::endl;
            playerBullet->move(1.f); 
            std::cout << "Player bullet moved" << std::endl;
        } else {
            playerBullet->move(-1.f); // move down
        }
    }
}
//constructor
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initEnemies();
    this->playerBullet = nullptr;
}
//destructor
Game::~Game()
{
    delete this->window;
}


//Accessors
const bool Game::running() const
{
    return this->window->isOpen();
}
void Game::pollEvent()
{
    //event polling
    while(this->window->pollEvent(this->ev)) 
    {
        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                } else if (this->ev.key.code == sf::Keyboard::A) {
                    this->player.move('l');
                } else if (this->ev.key.code == sf::Keyboard::D) {
                    this->player.move('r');
                } else if (this->ev.key.code == sf::Keyboard::Space) {
                    this->fireBullet();
                }
                break;
        }
    }
}

//functions
void Game::update() //all the logic, moving, positon, collision, etc
{

    
    this->pollEvent(); //event polling
    if (playerBullet != nullptr) {
        playerBullet->move(1.f);
        
        // Check if the bullet is off the screen
        if (playerBullet->getPosition().y < 0) {
            // Delete the bullet if it's off the screen
            delete playerBullet;
            playerBullet = nullptr;
        }
    }
    //update mouse position
    //std::cout << "Mouse Pos: " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << std::endl;
    
}
void Game::render() //renders game objects
{
    this->window->clear();
    //draw game
    this->window->draw(this->enemy);
    this->window->draw(this->player);
    if (playerBullet != nullptr) {
        this->window->draw(*playerBullet);
    }
    this->window->display();
}
