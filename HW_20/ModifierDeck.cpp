#include "ModifierDeck.h"

#include "Modifier.h"

ModifierDeck::ModifierDeck()
{
	m_modifiersDatabase = 
	{
		new SimpleModifier{3},
		new SimpleModifier{3},
		new SimpleModifier{2},
		new SimpleModifier{2},
		new SimpleModifier{2},
		new SimpleModifier{4},
		new SimpleModifier{1},
		new SimpleModifier{1},
		new SimpleModifier{1},
		new DoubleMunchkinLevel{},
		new DoubleMunchkinLevel{},
		new HalvesMonsterLevel{Tribe::Undead},
		new HalvesMonsterLevel{Tribe::God}
	};
}

ModifierDeck::~ModifierDeck()
{
	for (auto modifier : m_modifiersDatabase) {
		delete modifier;
	}
	m_modifiersDatabase.clear();
}

Modifier* ModifierDeck::generateModifier() const
{
	static std::vector<Modifier*> availableModifiers = m_modifiersDatabase;

	if (availableModifiers.empty()) {
		availableModifiers = m_modifiersDatabase;
	}

	unsigned int idx = std::rand() % availableModifiers.size();
	Modifier* selectedModifier = availableModifiers[idx];
	availableModifiers.erase(availableModifiers.begin() + idx);

	return selectedModifier;
}
