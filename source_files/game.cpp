#include "../headers/game.h"
//private functions
void Game::initVariables()
{
    this->window = nullptr;
    
}
void Game::initWindow()
{
    this -> videoMode = sf::VideoMode(1000, 800);
    this->window = new sf::RenderWindow(this->videoMode, "SPACE INVADERS", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
    
}
void Game::initPlayer()
{
    this->player = Player();
}   

void Game::initEnemies()
{
    enemies = new Enemy**[5];  // Allocate the rows
    for (int i = 0; i < 5; ++i)
    {
        enemies[i] = new Enemy*[11];  // Allocate the columns
    }

    // Initialize the Enemy objects
    for (int i = 0; i < 11; ++i)
    {
        enemies[0][i] = new Enemy(Type::chonker, sf::Vector2f(leftBound + i * 50, 100));
    }
    for (int j = 0; j < 2; ++j)
    {
        for (int i = 0; i < 11; ++i)
        {
            enemies[j+1][i] = new Enemy(Type::bonker, sf::Vector2f(leftBound + i * 50, 155 + j * 55));
        }
    }
    for (int j = 0; j < 2; ++j)
    {
        for (int i = 0; i < 11; ++i)
        {
            enemies[j+3][i] = new Enemy(Type::donker, sf::Vector2f(leftBound + i * 50, 265 + j * 55));
        }
    }
}
void Game::fireBullet() {
    // Only create a new bullet if there isn't one already

    if (playerBullet == nullptr) {
        playerBullet = player.shoot();
    }
    if (playerBullet != nullptr) {
        if (playerBullet->getIsPlayerBullet()) {
            playerBullet->move(1.f); 
        } else {
            playerBullet->move(-1.f); // move down
        }
    }
}
void Game::addEnemyBullet(bullet* b) {
    enemyBullets.push_back(b);
}
void Game::removeEnemyBullet(bullet* b) {
    enemyBullets.erase(std::remove(enemyBullets.begin(), enemyBullets.end(), b), enemyBullets.end());
}
void Game::updateEnemyBullets() {
    for (int i = 0; i < enemyBullets.size(); i++) {
        bullet* b = enemyBullets.at(i);
        b->move(8.f);
        if (b->getPosition().y > 600) {
            removeEnemyBullet(b);
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
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 11; ++j)
        {
            delete enemies[i][j];
        }
        delete[] enemies[i];
    }
    delete[] enemies;

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
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                }
                if (this->ev.key.code == sf::Keyboard::Space) {
                    this->fireBullet();
                }

            // Player movement
                if (this->ev.key.code == sf::Keyboard::A) {
                    playerDirectionA = Direction::Left;
                } else if (this->ev.key.code == sf::Keyboard::D) {
                    playerDirectionD = Direction::Right;
                }
                break;
            case sf::Event::KeyReleased:
                if (this->ev.key.code == sf::Keyboard::A) {
                    playerDirectionA = Direction::None;
                } else if (this->ev.key.code == sf::Keyboard::D) {
                    playerDirectionD = Direction::None;
                }
                break;
    }
}
}

//functions
void Game::update() //all the logic, moving, positon, collision, etc
{

    this->updateEnemyBullets();

    this->pollEvent(); //event polling
    if (playerBullet != nullptr) {
        playerBullet->move(10.f);
        
        // Check if the bullet is off the screen
        if (playerBullet->getPosition().y < 0) {
            delete playerBullet;
            playerBullet = nullptr;
        }
    }
    // Enemy movement

    
    // Player movement

    if (playerDirectionA == Direction::Left && playerDirectionD != Direction::Right) {
        this->player.move('l');
    } else if (playerDirectionD == Direction::Right && playerDirectionA != Direction::Left) {
        this->player.move('r');
    }
    // Collision detection
    
    //update mouse position
    //std::cout << "Mouse Pos: " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << std::endl;
    
}
void Game::render() //renders game objects
{
    this->window->clear();
    //draw game
    
    for (int i = 0; i < 5; i++) { // Make sure this loop runs 5 times
    for (int j = 0; j < 11; j++) {
        if (enemies[i][j] != NULL) {
            this->window->draw(*enemies[i][j]);
        }
    }
}

    for (int i = 0; i < enemyBullets.size(); i++) {
        this->window->draw(*enemyBullets.at(i));
    }

    if (playerBullet != nullptr) {
        this->window->draw(*playerBullet);
    }
    this->window->draw(this->player);
    this->window->display();
}
