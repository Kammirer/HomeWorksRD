#include "ItemDeck.h"

#include "Item.h"
#include <ctime>
#include <fstream>
#include <sstream>

const int maxItems = 3;

ItemDeck::ItemDeck()
{
	std::fstream file;
	file.open("ItemsBase.txt", std::ios::in);
	if (!file) {
		m_itemsDataBase =
			{ new Weapon{"The Sword of DOOM", 5},
			new UndeadWeapon{"Stinky knife", 2},
			new UndeadWeapon{"Holy grenade", 5},
			new HolySword{"Holy silver sword", 3},
			new Plague{"Plague bomb", 4},
			new HolySword{"Witch sword", 7},
			new Plague{"Plague rats", 2},
			new UndeadWeapon{"Holy water", 6} };
	}
	else {
		std::string line;
		while (std::getline(file, line)) {
			std::istringstream iss(line);
			std::string type, name, level_str;

			if (std::getline(iss, type, ';') && std::getline(iss, name, ';') && std::getline(iss, level_str, ';')) {
				int level = std::stoi(level_str);
				if (type == "Weapon") {
					m_itemsDataBase.push_back(new Weapon{ name, level });
				}
				else if (type == "UndeadWeapon") {
					m_itemsDataBase.push_back(new UndeadWeapon{ name, level });
				}
				else if (type == "HolySword") {
					m_itemsDataBase.push_back(new HolySword{ name, level });
				}
				else if (type == "Plague") {
					m_itemsDataBase.push_back(new Plague{ name, level });
				}
			}
		}
	}
	file.close();
}

ItemDeck::~ItemDeck()
{
	for (auto item : m_itemsDataBase) {
		delete item;
	}
}

std::vector<Item*> ItemDeck::generateItems()
{
	int randVar = 0;
	int i = 0;
	std::srand(static_cast<int>(std::time(0)));
	while (i < maxItems) {
		randVar = rand() % (m_itemsDataBase.size());
		m_itemsOnHand.push_back(m_itemsDataBase[randVar]);
		m_itemsDataBase.erase(m_itemsDataBase.begin() + randVar);
		i++;
	}
	return m_itemsOnHand;
}