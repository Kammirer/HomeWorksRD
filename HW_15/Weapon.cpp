#include <iostream>
#include "Weapon.h"

void Weapon::printInfoWeapon() const {
	std::cout << " | Weapon: " << name << " - damage: " << damage << ", range: " << range;
}