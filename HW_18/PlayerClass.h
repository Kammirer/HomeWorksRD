#pragma once
#include <string>

class PlayerClass
{
public:
	virtual float getDamageMultiplier() const = 0;
	virtual float getDefenseMultiplier() const = 0;
};

class DefaultClass : public PlayerClass
{
public:
	virtual float getDamageMultiplier() const override;
	virtual float getDefenseMultiplier() const override;
};

class DefenderClass : public DefaultClass
{
public:
	virtual float getDefenseMultiplier() const override;
};

class AttackerClass : public DefaultClass {
public:
	virtual float getDamageMultiplier() const override;
};