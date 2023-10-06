#pragma once
#include <SFML/Graphics.hpp>
#include "ViewModel.h"

class Scena
{
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
};

class Widget
{
public:
	virtual void draw(sf::RenderWindow* window) = 0;
	virtual void setPosition(sf::Vector2f position) = 0;
};

class TextWidget : public Widget
{
public:
	TextWidget() {
		m_Font.loadFromFile("Runer\\Font\\CroissantOne.ttf");
		m_Text.setFont(m_Font);
		m_Text.setCharacterSize(34);
		m_Text.setFillColor(sf::Color::Red);
		m_Text.setOutlineThickness(1);
		m_Text.setOutlineColor(sf::Color::White);
	}

	void draw(sf::RenderWindow* window) override {
		window->draw(m_Text);
	}

	void setPosition(sf::Vector2f position) override
	{
		m_Text.setPosition(position);
	}

	void setText(const std::string& text) {
		m_Text.setString(text);
	}

private:
	sf::Text m_Text;
	sf::Font m_Font;
};

class GameHUD : public Scena
{
public:
	GameHUD(Player* player) {
		m_HUDVM = new GameHUDVM(player);

		m_healthBar.setPosition({ 50, 720 });
		m_scoreBar.setPosition({ 1200, 720 });
	}

	void update() override {
		m_healthBar.setText("Health: " + std::to_string(m_HUDVM->getHealth()));
		m_scoreBar.setText("Score: " + std::to_string(m_HUDVM->getScore()));
	};

	void draw(sf::RenderWindow* window) override {
		m_healthBar.draw(window);
		m_scoreBar.draw(window);
	};

private:
	TextWidget m_healthBar;
	TextWidget m_scoreBar;

	GameHUDVM* m_HUDVM = nullptr;
};

class PauseHUD : public Scena
{
public:
	PauseHUD() {
		m_pauseBar.setPosition({ 700, 350 });
	}

	void update() override {
		m_pauseBar.setText("PAUSE!");
	};

	void draw(sf::RenderWindow* window) override {
		m_pauseBar.draw(window);
	};

private:
	TextWidget m_pauseBar;
};

class StartHUD : public Scena
{
public:
	StartHUD() {
		m_pauseBar.setPosition({ 100, 50 });
	}

	void update() override {
		m_pauseBar.setText("Erebonia!\nA wild and gloomy land where the struggle of dark and light\nmagic is constantly going on!\nIn the settlement called Lovecon lived 2 brothers - John and Eric.\nSo they decided to check one of the legends of the dark forest:\n'They say that there is one witch living in the forest who can\nfulfill only one wish. However, this wish must be quite protected.'\nThe brothers went to the forest... They walked along dark paths,\nbypassing thick and thorny thickets.Suddenly, a giant spider\nappeared on their path, which grabbed the younger Eric and\ndragged him into equally dark thickets.\nSo John was left alone..!\n\n...Press ENTER to continue...");
	};

	void draw(sf::RenderWindow* window) override {
		m_pauseBar.draw(window);
	};

private:
	TextWidget m_pauseBar;
};

class GameOverHUD : public Scena
{
public:
	GameOverHUD(Player* player) {
		m_HUDVM = new GameHUDVM(player);

		m_GameOverhBar.setPosition({ 600, 300 });
		m_scoreBar.setPosition({ 620, 350 });
	}

	void update() override {
		m_GameOverhBar.setText("GAME OVER!");
		m_scoreBar.setText("Score: " + std::to_string(m_HUDVM->getScore()));
	};

	void draw(sf::RenderWindow* window) override {
		m_GameOverhBar.draw(window);
		m_scoreBar.draw(window);
	};

private:
	TextWidget m_GameOverhBar;
	TextWidget m_scoreBar;

	GameHUDVM* m_HUDVM = nullptr;
};