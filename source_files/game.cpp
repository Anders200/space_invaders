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
    this->player.setSize(sf::Vector2f(50.0f, 50.0f));
    this->player.setFillColor(sf::Color::White);
    this->player.setPosition(sf::Vector2f(10.0f, 10.0f));
}
void Game::initEnemies() {
    this->enemy.setPosition(sf::Vector2f(100.0f, 100.0f));
    this->enemy.setSize(sf::Vector2f(50.0f, 50.0f));
    this->enemy.setFillColor(sf::Color::Red);
    this->enemy.setOutlineColor(sf::Color::Black);
    this->enemy.setOutlineThickness(1.0f);
}
//constructor
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initEnemies();
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
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

//functions
void Game::update() //all the logic, moving, positon, collision, etc
{

    
    this->pollEvent(); //event polling

    //update mouse position
    std::cout << "Mouse Pos: " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << std::endl;
    
}
void Game::render() //renders game objects
{
    this->window->clear();
    //draw game
    this->window->draw(this->enemy);

    this->window->display();
}
