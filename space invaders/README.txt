This is classic space invaders game, not much resources just game logic, loosing condition and some score. 



Game was written using SFML graphic library

Game logic is pretty much done, I could add some resources like enemy textures, bullet animations, loosing screen but there is not much more programming to do here.

I would like to ask for feedback here if this is good enough or I should add something else like a boss fight, platforms, new levels.


to compile:

g++ source_files/main.cpp source_files/game.cpp source_files/bullet.cpp source_files/enemy.cpp source_files/player.cpp source_files/lifes.cpp -lsfml-graphics -lsfml-window -lsfml-system

