#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
};

class Player : public GameObject
{
public:
	Player(sf::Vector2f position, int playerHealth);

	void update(float deltaTime) override;
	void draw(sf::RenderWindow* window) override;

	void setPosition(sf::Vector2f playerPosition) { m_sprite.setPosition(playerPosition); };

	sf::Sprite getSprite() { return m_sprite; };

	int getHealthPlayer() { return m_playerHealth; };
	void setHealthDown();

	int getScorePlayer() { return m_playerScore; };
	void setScore();
private:
	sf::Vector2f m_position;
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	int m_playerHealth = 0;
	int m_playerScore = 0;

	std::vector<sf::Texture> m_textureStay;
	std::vector<sf::Texture> m_textureRun;

	std::vector<sf::Sprite> m_spriteStay;
	std::vector<sf::Sprite> m_spriteRun;

	int m_currentFrameStay;
	int m_currentFrameRun;

	float m_frameDurationStay;
	float m_frameDurationRun;
	float m_frameTimer;

	float m_animationSpeedStay;
	float m_animationSpeedRun;
};

class Enemy : public GameObject
{
public:
	Enemy();

	void update(float deltaTime) override;
	void draw(sf::RenderWindow* window) override;
	void reset();

	sf::Sprite getSprite() { return m_sprite; };
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	const float m_fallSpeed = 300.0f;
};

class Coin : public GameObject
{
public:
	Coin();

	void update(float deltaTime) override;
	void draw(sf::RenderWindow* window) override;
	void reset();

	sf::Sprite getSprite() { return m_sprite; };
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	const float m_fallSpeed = 200.0f;
};