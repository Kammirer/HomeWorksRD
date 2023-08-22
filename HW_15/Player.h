#pragma once
#include <string>
#include "Weapon.h"
#include "Classification.h"

class Player {
private:
	std::string name;
	int health;
	Classification classPlayer;

public:
	Player(const std::string name_par, int health_par, Classification classPlayer_par) {
		name = name_par;
		health = health_par;
		classPlayer = classPlayer_par;
	}

	std::string teamPl;
	Weapon* playersWeapons;

	void addWeapon(Weapon* weapon);
	void printInfoPlayer() const;
};