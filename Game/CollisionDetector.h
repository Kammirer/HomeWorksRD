#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameObjects.h"

class CollisionDetector
{
public:
    CollisionDetector(sf::Music* soundEnemy, sf::Music* soundCoin);

    static void checkCollision(Player* player, std::vector<Enemy>* enemies, std::vector<Coin>* coins);

private:
    static sf::Music* collisionSoundEnemy;
    static sf::Music* collisionSoundCoin;
};