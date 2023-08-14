#include "Weapon.h"

float SniperRifle::getPrecision(int distance) const
{
	if (distance > 2000)
	{
		return 0.2f;
	}
	if (distance > 1000)
	{
		return 1.5f;
	}
	if (distance > 300)
	{
		return 5.0f;
	}
	return 1.0f;
}

float Pistol::getPrecision(int distance) const {
	if (distance > 1000) {
		return 0.1f;
	}
	if (distance > 500) {
		return 0.8f;
	}
	if (distance > 200) {
		return 1.5f;
	}
	return 3.0f;
}

float AssaultRifle::getPrecision(int distance) const {
	if (distance > 1500) {
		return 0.5f;
	}
	if (distance > 700) {
		return 1.5f;
	}
	if (distance > 250) {
		return 2.8f;
	}
	return 4.0f;
}

float Shotgun::getPrecision(int distance) const {
	if (distance > 500) {
		return 0.5f;
	}
	if (distance > 150) {
		return 3.5f;
	}
	return 7.0f;
}