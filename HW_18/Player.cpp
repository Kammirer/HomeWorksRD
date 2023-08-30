#include "Player.h"

const int healingPlayer = 30;

void Player::setWeapon(Weapon* weapon)
{
	delete m_weapon;
	m_weapon = weapon;
}

void Player::setPlayerClass(PlayerClass* playerClass)
{
	delete m_class;
	m_class = playerClass;
}

void Player::setTeam(Team* team) {
	delete m_team;
	m_team = team;
}

void Player::attack(Player& other, int distance)
{
	int healthPlayer = 0;

	if (isEliminated()) {
		return;
	}

	if (other.isEliminated())
	{
		std::cout << "Player " << other.getName() << " has been already eliminated!\n";
		return;
	}
	
	if (revers) {
		if (m_team->getTeamName() == other.m_team->getTeamName()) {
			std::cout << "\n-------REVERSE FIRE!\n";
			if (&other != this)
			{
				const int damage = static_cast<int>(m_weapon->getDamageRate(distance) * m_class->getDamageMultiplier() / other.m_class->getDefenseMultiplier());

				healthPlayer = m_health;
				healthPlayer -= damage;
				setHealth(m_health);

				std::cout << "Player " << getName() << " attacked Player " << other.getName() << " with damage " << damage << " - REVERSE FIRE!" << std::endl;
				std::cout << getName() << ": Health left: " << healthPlayer << std::endl;
			}
			else {
				const int damage = static_cast<int>(m_weapon->getDamageRate(distance) * m_class->getDamageMultiplier() / other.m_class->getDefenseMultiplier());

				healthPlayer = getHealth(other);
				healthPlayer -= damage;
				other.setHealth(healthPlayer);

				std::cout << "Player " << getName() << " attacked Player " << other.getName() << " with damage " << damage << std::endl;
				std::cout << other.getName() << ": Health left: " << healthPlayer << std::endl;
			}
		}
	}
	else {
		if (m_team->getTeamName() == other.m_team->getTeamName()) { 
			std::cout << "\n-------FRIENDLY FIRE!-------\n"; 
			if (&other != this)
			{
				std::cout << "-------Warning! Reverse fire activated!\n";
				revers = true;
			}
		}

		const int damage = static_cast<int>(m_weapon->getDamageRate(distance) * m_class->getDamageMultiplier() / other.m_class->getDefenseMultiplier());

		healthPlayer = getHealth(other);
		healthPlayer -= damage;
		other.setHealth(healthPlayer);

		std::cout << "Player " << getName() << " attacked Player " << other.getName() << " with damage " << damage << std::endl;
		std::cout << other.getName() << ": Health left: " << healthPlayer << std::endl;
	}

	if (healthPlayer <= 0)
	{
		other.setHealth(0);
		std::cout << "Player " << other.getName() << " was eliminated!\n";
	}
}

void Player::healing(const Player& player) {
	if (!player.isEliminated()) {
		std::cout << "\n-------Player " << getName() << " healing...\n";
		if (player.heal()) {
			m_health += healingPlayer;
			m_heal--;
			std::cout << "Health: " << m_health << "\n";
		}
		else {
			std::cout << "Oops... No more healing bottle!\n";
		}
	}
}