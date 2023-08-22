#include  <iostream>
#include "Player.h"
#include "Classification.h"

void Player::addWeapon(Weapon* weapon) {
	playersWeapons = weapon;
}

void Player::printInfoPlayer() const {
	std::cout << "Player: " << name << " - health: " << health << ", class: " << getClassification(classPlayer);
	playersWeapons->printInfoWeapon();
	std::cout << " | Team: " << teamPl << std::endl;
}