#include "Team.h"

void Team::addPlayer(Player* player) {
	players.push_back(player);
	player->teamPl = name;
}

void Team::removePlayer(Player* player) {
	for (auto it = players.begin(); it != players.end(); ++it) {
		if (*it == player) {
			players.erase(it);
			player->teamPl = "";
			break;
		}
	}
}