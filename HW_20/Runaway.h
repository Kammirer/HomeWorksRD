#pragma once
#include <string>

class Munchkin;

class Runaway
{
public:
	virtual void apply(Munchkin* munchkin) = 0;

	virtual std::string getFullInfo() { return ""; }
};

class Runaway_LevelDowngrade : public Runaway
{
public:
	Runaway_LevelDowngrade(int level = 1) : m_levelToDowngrade(level) {}
	void apply(Munchkin* munchkin) override;

	virtual std::string getFullInfo() override {
		return " = Downgrade your level by " + std::to_string(m_levelToDowngrade) + " =\n\n";
	}
protected:
	int m_levelToDowngrade;
};

class Runaway_LevelDowngradeIf : public Runaway_LevelDowngrade
{
public:
	Runaway_LevelDowngradeIf(int level, int minimalMunchkinLevel) 
		: Runaway_LevelDowngrade(level), m_minimalMunchkinLevelToApply(minimalMunchkinLevel) {}

	void apply(Munchkin* munchkin) override;

	virtual std::string getFullInfo() override {
		return " = Downgrade your level by " + std::to_string(m_levelToDowngrade) + " =\n\n";
	}

private:
	int m_minimalMunchkinLevelToApply;
};

class Runaway_ModifierFromHandRemoval : public Runaway
{
public:
	Runaway_ModifierFromHandRemoval(int cardRemove) : m_cardRemove(cardRemove) {}

	void apply(Munchkin* munchkin) override;

	virtual std::string getFullInfo() override {
		return " = You lost " + std::to_string(m_cardRemove) + " card(-s) from hands! =\n\n";
	}

private:
	int m_cardRemove;
};

class Runaway_ItemEquipedRemoval : public Runaway
{
public:
	Runaway_ItemEquipedRemoval(int itemRemove) : m_itemRemove(itemRemove) {}

	void apply(Munchkin* munchkin) override;

	virtual std::string getFullInfo() override {
		return " = You lost " + std::to_string(m_itemRemove) + " ITEM! =\n\n";
	}
private:
	int m_itemRemove;
};