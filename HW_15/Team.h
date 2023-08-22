#pragma once
#pragma once
#include <string>
#include <vector>
#include "Player.h"

class Team {
private:
	std::string name;
	int numPlayers;
	std::vector<Player*> players;

public:
	Team(const std::string& name_par, int numPlayers_par)
	{
		name = name_par;
		numPlayers = numPlayers_par;
	}

	void addPlayer(Player* player);
	void removePlayer(Player* player);
};