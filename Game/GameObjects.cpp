#include "GameObjects.h"

// Player
Player::Player(sf::Vector2f position, int playerHealth)
{
    m_position = position;
    m_playerHealth = playerHealth;

    // Stay
    const int m_stay = 3;
    const std::string m_pathStay = "Runer\\Player\\stay\\";
    const std::string m_nameStay = "stay";
    m_animationSpeedStay = 0.75f;
    m_frameDurationStay = m_animationSpeedStay / m_stay;
    m_currentFrameStay = 0;
    m_frameTimer = 0;

    m_textureStay.resize(m_stay);
    m_spriteStay.resize(m_stay);
    for (int i = 0; i < m_stay; i++) {
        m_textureStay[i].loadFromFile(m_pathStay + m_nameStay + std::to_string(i + 1) + ".png");
        m_spriteStay[i].setTexture(m_textureStay[i]);
        m_spriteStay[i].setOrigin(m_textureStay[i].getSize().x / 2.0f, m_textureStay[i].getSize().y / 2.0f);
        m_spriteStay[i].setPosition(m_position);
    }
    // Stay

    // Run
    const int m_run = 6;
    const std::string m_pathRun = "Runer\\Player\\run\\";
    const std::string m_nameRun = "run";
    m_animationSpeedRun = 0.5f;
    m_frameDurationRun = m_animationSpeedRun / m_run;
    m_currentFrameRun = 0;

    m_textureRun.resize(m_run);
    m_spriteRun.resize(m_run);
    for (int i = 0; i < m_run; i++) {
        m_textureRun[i].loadFromFile(m_pathRun + m_nameRun + std::to_string(i + 1) + ".png");
        m_spriteRun[i].setTexture(m_textureRun[i]);
        m_spriteRun[i].setOrigin(m_textureRun[i].getSize().x / 2.0f, m_textureRun[i].getSize().y / 2.0f);
        m_spriteRun[i].setPosition(m_position);
    }
    // Run
}

void Player::update(float deltaTime)
{
    constexpr float MoveDeltaPerSecond = 400.0f;
    const float MoveDelta = MoveDeltaPerSecond * deltaTime;

    sf::Vector2f position = m_sprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        m_frameTimer -= deltaTime;

        if (m_frameTimer <= 0)
        {
            m_currentFrameRun++;
            m_currentFrameRun %= m_textureRun.size();
            m_frameTimer = m_frameDurationRun;
        }

        m_spriteRun[0].setTexture(m_textureRun[m_currentFrameRun]);
        m_spriteRun[0].setScale(1, 1);
        m_spriteRun[0].setPosition(m_position);

        if (m_position.x + m_spriteRun[0].getGlobalBounds().width / 2 < 1500)
        {
            m_position.x += MoveDelta;
        }
        m_sprite = m_spriteRun[0];
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        m_frameTimer -= deltaTime;

        if (m_frameTimer <= 0)
        {
            m_currentFrameRun++;
            m_currentFrameRun %= m_textureRun.size();
            m_frameTimer = m_frameDurationRun;
        }

        m_spriteRun[0].setTexture(m_textureRun[m_currentFrameRun]);
        m_spriteRun[0].setScale(-1, 1);
        m_spriteRun[0].setPosition(m_position);

        if (m_position.x - m_spriteRun[0].getGlobalBounds().width / 2 > 0)
        {
            m_position.x -= MoveDelta;
        }
        m_sprite = m_spriteRun[0];
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)
        && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        m_frameTimer -= deltaTime;

        if (m_frameTimer <= 0)
        {
            m_currentFrameStay++;
            if (m_currentFrameStay >= m_textureStay.size())
            {
                m_currentFrameStay = 0;
            }
            m_frameTimer = m_frameDurationStay;
        }

        sf::Vector2f currentScale = m_spriteRun[0].getScale();
        m_spriteStay[0].setTexture(m_textureStay[m_currentFrameStay]);
        m_spriteStay[0].setScale(currentScale);
        m_spriteStay[0].setPosition(m_position);
        m_sprite = m_spriteStay[0];
    }
}

void Player::draw(sf::RenderWindow* window)
{
    window->draw(m_sprite);
}

void Player::setHealthDown()
{
    m_playerHealth--;
}

void Player::setScore()
{
    m_playerScore += 150;
    if (m_playerScore % 6000 == 0)
    {
        m_playerHealth++;
    }
}

// Enemy
Enemy::Enemy()
{
    m_sprite.setOrigin(m_texture.getSize().x / 2.0f, m_texture.getSize().y / 2.0f);
    reset();
}

void Enemy::update(float deltaTime)
{
    float y = m_sprite.getPosition().y + m_fallSpeed * deltaTime;
    m_sprite.setPosition(m_sprite.getPosition().x, y);

    if (y > 650) { reset(); }
}

void Enemy::reset()
{
    m_texture.loadFromFile("Runer\\Enemy\\enemy.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(static_cast<float>(rand() % 1500), 0);
}

void Enemy::draw(sf::RenderWindow* window)
{
    window->draw(m_sprite);
}

// Coin
Coin::Coin()
{
    m_sprite.setOrigin(m_texture.getSize().x / 2.0f, m_texture.getSize().y / 2.0f);
    reset();
}

void Coin::update(float deltaTime)
{
    float y = m_sprite.getPosition().y + m_fallSpeed * deltaTime;
    m_sprite.setPosition(m_sprite.getPosition().x, y);

    if (y > 620) { reset(); }
}

void Coin::reset()
{
    m_texture.loadFromFile("Runer\\Obj\\coin.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(static_cast<float>(rand() % 1500), 0);
}

void Coin::draw(sf::RenderWindow* window)
{
    window->draw(m_sprite);
}