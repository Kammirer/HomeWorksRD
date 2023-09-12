#include "MonsterDeck.h"

#include "Monster.h"
#include "Runaway.h"

MonsterDeck::MonsterDeck()
{
	m_monstersDatabase =
	{
		new Monster{"Crazy Joe", 4},
		new Monster{"Vampire", 3, Tribe::Undead, new Runaway_LevelDowngrade{1}},
		new Monster{"Shiva destructor", 20, Tribe::God, new Runaway_ItemEquipedRemoval{1}},
		new Monster{"Dark horse", 8, Tribe::Zombie, new Runaway_ModifierFromHandRemoval{1}},
		new Monster{"Lord of Death", 13, Tribe::Undead, new Runaway_LevelDowngradeIf{1, 3}},
		new Monster{"Rogue Frog", 19, Tribe::Undead, new Runaway_ModifierFromHandRemoval{3}},
		new Monster{"Ra", 5, Tribe::God, new Runaway_LevelDowngrade{2}},
		new Monster{"Intelligent Zombie", 8, Tribe::Zombie, new Runaway_LevelDowngrade{2}},
		new Monster{"John Wick", 15, Tribe::Human, new Runaway_ModifierFromHandRemoval{2}},
		new Monster{"Kratos", 12, Tribe::God, new Runaway_ItemEquipedRemoval{1}},
		new Monster{"Witch", 15, Tribe::Human, new Runaway_LevelDowngradeIf{3, 4}}
	};
}

MonsterDeck::~MonsterDeck()
{
	for (auto monster : m_monstersDatabase) {
		delete monster;
	}
}

Monster* MonsterDeck::generateMonster() 
{
	if (m_unusedMonsters.empty()) {
		m_unusedMonsters = m_monstersDatabase;
	}

	const int choice = std::rand() % m_unusedMonsters.size();

	Monster* selectedMonster = m_unusedMonsters[choice];
	m_unusedMonsters.erase(m_unusedMonsters.begin() + choice);

	return selectedMonster;
}