#pragma once
#include <string>

class Team {
public:
	virtual std::string getTeamName();
};

class RedTeam : public Team {
public:
	virtual std::string getTeamName() override;
};

class BlueTeam : public Team {
public:
	virtual std::string getTeamName() override;
};