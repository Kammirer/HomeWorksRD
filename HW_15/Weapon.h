#pragma once
#include <string>

class Weapon {
public:
	Weapon(const std::string name_par, int damage_par, int range_par) {
		name = name_par;
		damage = damage_par;
		range = range_par;
	}

	void printInfoWeapon() const;

private:
	std::string name;
	int damage;
	int range;
};