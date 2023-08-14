#pragma once

class Weapon
{
public:
	virtual int getDamageRate(int distance) const = 0;
};

class RangedWeapon : public Weapon
{
public:
	int getDamageRate(int distance) const override { return static_cast<int>(getPrecision(distance) * 10); }

protected:
	//Default value
	virtual float getPrecision(int distance) const { return 1.0f; }
};

class SniperRifle : public RangedWeapon
{
protected:
	virtual float getPrecision(int distance) const override;
};

class Pistol : public RangedWeapon
{
protected:
	virtual float getPrecision(int distance) const override;
};

class AssaultRifle : public RangedWeapon
{
protected:
	virtual float getPrecision(int distance) const override;
};

class Shotgun : public RangedWeapon
{
protected:
	virtual float getPrecision(int distance) const override;
};

class MeleeWeapon : public Weapon
{
public:
	virtual int getDamageRate(int distance) const override
	{
		return 10;
	}
};

class BareHand : public MeleeWeapon
{
public:
	virtual int getDamageRate(int distance) const override
	{
		return 5;
	}
};

class Axe : public MeleeWeapon
{
public:
	virtual int getDamageRate(int distance) const override
	{
		return 45;
	}
};

class Knife : public MeleeWeapon
{ 
public:
	virtual int getDamageRate(int distance) const override
	{
		return 30;
	}
};

class Katana : public MeleeWeapon
{
public:
	virtual int getDamageRate(int distance) const override
	{
		return 70;
	}
};