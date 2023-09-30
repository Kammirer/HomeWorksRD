#include "CollisionDetector.h"

sf::Music* CollisionDetector::collisionSoundEnemy = nullptr;
sf::Music* CollisionDetector::collisionSoundCoin = nullptr;

CollisionDetector::CollisionDetector(sf::Music* soundEnemy, sf::Music* soundCoin)
{
    collisionSoundEnemy = soundEnemy;
    collisionSoundCoin = soundCoin;
}

void CollisionDetector::checkCollision(Player* player, std::vector<Enemy>* enemies, std::vector<Coin>* coins)
{
    const sf::Sprite sp1 = player->getSprite();

    for (Enemy& enemy : *enemies) {
        const sf::Sprite sp2 = enemy.getSprite();

        if (sp1.getGlobalBounds().intersects(sp2.getGlobalBounds()))
        {
            enemy.reset();
            player->setHealthDown();
            collisionSoundEnemy->play();
        }
    }

    for (Coin& coin : *coins) {
        const sf::Sprite sp2 = coin.getSprite();

        if (sp1.getGlobalBounds().intersects(sp2.getGlobalBounds()))
        {
            coin.reset();
            player->setScore();
            collisionSoundCoin->play();
        }
    }
}