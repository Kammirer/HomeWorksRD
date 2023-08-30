#include "Team.h"
#include <string>

std::string Team::getTeamName() {
	return "DEFAULT";
}

std::string RedTeam::getTeamName() {
	return "RED";
}

std::string BlueTeam::getTeamName() {
	return "BLUE";
}