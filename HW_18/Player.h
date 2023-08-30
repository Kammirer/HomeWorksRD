#pragma once
#include <string>
#include <iostream>
#include "PlayerClass.h"
#include "Weapon.h"
#include "Team.h"

class Player
{
public:
	Player(const std::string& name = "Auto Generated NameId", Weapon* weapon = new BareHand, PlayerClass* playerClass = new DefaultClass, Team* team = new Team)
		: m_name(name), m_weapon(weapon), m_class(playerClass), m_team(team) {}
	~Player()
	{
		delete m_class;
		delete m_weapon;
		delete m_team;
	}

	std::string getName() const { return m_name; }
	int getBaseDamage(int distance) { return m_weapon->getDamageRate(distance); }

	void setWeapon(Weapon* weapon);
	void setPlayerClass(PlayerClass* playerClass);
	void setTeam(Team* team);
	void setHealth(int health) { m_health = health; }
	bool isEliminated() const { return m_health <= 0; }
	
	bool heal() const { return m_heal > 0; }
	int getHealth(const Player& player) { return player.m_health; }

	void attack(Player& other, int distance);
	void healing(const Player& player);


private:
	int m_health = 100;
	std::string m_name;
	int m_heal = 1;
	bool revers = false;

	PlayerClass* m_class = nullptr;
	Weapon* m_weapon = nullptr;
	Team* m_team = nullptr;
};