#include "PlayerClass.h"

float DefaultClass::getDamageMultiplier() const {
	return 1.0f;
}

float DefaultClass::getDefenseMultiplier() const {
	return 1.0f;
}

float DefenderClass::getDefenseMultiplier() const {
	return 1.1f;
}

float AttackerClass::getDamageMultiplier() const {
	return 1.1f;
}