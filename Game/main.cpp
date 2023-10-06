#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "GameObjects.h"
#include "CollisionDetector.h"
#include "View.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1500, 800), "RUN, JOHNY! RUN!", sf::Style::Default);
	sf::Clock clock;

	// BG
	sf::Texture textureBG;
	textureBG.loadFromFile("Runer\\Obj\\background.png");
	sf::Sprite spriteBG(textureBG);

	sf::Texture textureStartBG;
	textureStartBG.loadFromFile("Runer\\Obj\\backgroundStart.png");
	sf::Sprite spriteStartBG(textureStartBG);

	// Sound
	sf::SoundBuffer buffer;
	buffer.loadFromFile("Runer\\Sounds\\soundBG.wav");
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.setVolume(1);
	sound.setLoop(true);
	sound.play();

	sf::Music collisionSoundEnemy;
	collisionSoundEnemy.openFromFile("Runer\\Sounds\\hitPlayer.wav");
	collisionSoundEnemy.setVolume(1);

	sf::Music collisionSoundCoin;
	collisionSoundCoin.openFromFile("Runer\\Sounds\\addCoin.wav");
	collisionSoundCoin.setVolume(1);

	CollisionDetector collisionDetector(&collisionSoundEnemy, &collisionSoundCoin);

	// Player
	constexpr float playerPositionX = 750.0f;
	constexpr float playerPositionY = 620.0f;
	constexpr int playerHealth = 5;
	sf::Vector2f playerPosition(playerPositionX, playerPositionY);
	Player player(playerPosition, playerHealth);

	// Enemy
	sf::Clock enemySpawnTimer;
	const sf::Time enemySpawnInterval = sf::seconds(1.5f);
	std::vector<Enemy> enemies;
	int maxEnemy = 5;

	// Coin
	sf::Clock coinSpawnTimer;
	const sf::Time coinSpawnInterval = sf::seconds(1.0f);
	std::vector<Coin> coins;
	int maxCoins = 3;

	// HUD
	GameHUD gameHUD(&player);
	bool isPaused = false;
	PauseHUD pauseHUD;
	GameOverHUD gameOverHUD(&player);
	bool isStart = true;
	StartHUD startHUD;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
			{
				isPaused = !isPaused;
			}
			if (isStart)
			{
				if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					isStart = !isStart;
				}
			}
		}

		const float deltaTime = clock.restart().asSeconds();

		if (isStart)
		{
			startHUD.update();
			window.draw(spriteStartBG);
			startHUD.draw(&window);
		}
		else
		{
			if (player.getHealthPlayer() != 0)
			{
				if (!isPaused)
				{
					CollisionDetector::checkCollision(&player, &enemies, &coins);

					// Update
					player.update(deltaTime);

					for (Enemy& enemy : enemies) {
						enemy.update(deltaTime);
					}
					if (enemies.size() < maxEnemy) {
						if (enemySpawnTimer.getElapsedTime() >= enemySpawnInterval) {
							enemies.emplace_back();
							enemySpawnTimer.restart();
						}
					}

					for (Coin& coin : coins) {
						coin.update(deltaTime);
					}
					if (coins.size() < maxCoins) {
						if (coinSpawnTimer.getElapsedTime() >= coinSpawnInterval) {
							coins.emplace_back();
							coinSpawnTimer.restart();
						}
					}
					// Update end
				}
			}
			gameHUD.update();
			pauseHUD.update();
			gameOverHUD.update();

			// Draw
			window.clear(sf::Color::Black);
			window.draw(spriteBG);

			if (player.getHealthPlayer() != 0)
			{
				player.draw(&window);

				for (Enemy& enemy : enemies) {
					enemy.draw(&window);
				}

				for (Coin& coin : coins) {
					coin.draw(&window);
				}

				if (!isPaused) {
					sf::Color color = spriteBG.getColor();
					color.a = 255;
					spriteBG.setColor(color);
					gameHUD.draw(&window);
				}
				else if (isPaused) {
					sf::Color color = spriteBG.getColor();
					color.a = 63;
					spriteBG.setColor(color);
					pauseHUD.draw(&window);
				}
			}
			else
			{
				sf::Color color = spriteBG.getColor();
				color.a = 63;
				spriteBG.setColor(color);
				gameOverHUD.draw(&window);
			}
			// Draw end
		}
		window.display();
	}

	return 0;
}