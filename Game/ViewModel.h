#pragma once
#pragma once
#include "GameObjects.h"

class ViewModel
{
	
};

class GameHUDVM : public ViewModel
{
public:
	GameHUDVM(Player* player) {
		m_player = player;
	}
	unsigned int getHealth() const { return m_player->getHealthPlayer(); };
	unsigned int getScore() const { return m_player->getScorePlayer(); };
private:
	Player* m_player;
};