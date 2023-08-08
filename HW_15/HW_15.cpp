#include <iostream>
#include <string>

enum class Classification { Assault, Support, Sniper, Medic };

std::string getClassification(Classification classPlayer) {
	switch (classPlayer) {
	case Classification::Assault:
		return "Assault";
	case Classification::Support:
		return "Support";
	case Classification::Sniper:
		return "Sniper";
	case Classification::Medic:
		return "Medic";
	}
}

class Rectangle {
private:
	float length;
	float height;

public:
	Rectangle() {
		length = 15;
		height = 7;
	}

	Rectangle(float length_par, float height_par) {
		length = length_par;
		height = height_par;
	}

	float getArea() {
		return length * height;
	}

	float getPerimeter() {
		return  2 * (length + height);
	}
};

const int maxWeapons = 1;

class Weapon {
private:
	std::string name;
	int damage;
	int range;

public:
	Weapon(const std::string name_par, int damage_par, int range_par) {
		name = name_par;
		damage = damage_par;
		range = range_par;
	}

	void printInfoWeapon() {
		std::cout << " | Weapon: " << name << " - damage: " << damage << ", range: " << range;
	}
};

class Player {
private:
	std::string name;
	int health;
	Classification classPlayer;

public:
	Player(const std::string name_par, int health_par, Classification classPlayer_par) {
		name = name_par;
		health = health_par;
		classPlayer = classPlayer_par;
	}

	std::string teamPl;
	Weapon* WeaponPlayer;
	void addWeapon(Weapon* weapon) {
		WeaponPlayer = weapon;
	}

	void printInfoPlayer() {
		std::cout << "Player: " << name << " - health: " << health << ", class: " << getClassification(classPlayer);
		WeaponPlayer->printInfoWeapon();
		std::cout << " | Team: " << teamPl << std::endl;
	}
};

class Team {
private:
	std::string name;
	int numPlayers;
	Player** players;

public:
	Team(const std::string& name_par, int numPlayers_par)
	{
		name = name_par;
		numPlayers = numPlayers_par;

		players = new Player * [numPlayers];
		for (int i = 0; i < numPlayers; i++) {
			players[i] = nullptr;
		}
	}

	void addPlayer(Player* player) {
		for (int i = 0; i < numPlayers; i++) {
			if (players[i] == nullptr) {
				players[i] = player;
				player->teamPl = name;
				return;
			}
		}
	}

	void removePlayer(Player* player) {
		for (int i = 0; i < numPlayers; i++) {
			if (players[i] == player) {
				players[i] = nullptr;
				player->teamPl = "";
				return;
			}
		}
	}
};

int main()
{
	// Step 1 - Rectangle
	Rectangle rect1;
	std::cout << "Default constructor:" << std::endl;
	std::cout << "Area: " << rect1.getArea() << std::endl;
	std::cout << "Perimeter: " << rect1.getPerimeter() << std::endl;

	std::cout << std::endl;

	Rectangle rect2(8, 3);
	std::cout << "Constructor with parameters:" << std::endl;
	std::cout << "Area: " << rect2.getArea() << std::endl;
	std::cout << "Perimeter: " << rect2.getPerimeter() << std::endl;

	std::cout << std::endl;

	// Step 2 - Player, weapon, team
	Player player1("ASH", 100, Classification::Assault);
	Player player2("SLEDGE", 110, Classification::Support);
	Player player3("FINKA", 110, Classification::Medic);

	Weapon weapon1("AK-74", 43, 3);
	Weapon weapon2("R4-C", 47, 1);
	Weapon weapon3("HAMMER", 60, 2);

	Team team1("RED", 5);
	Team team2("BLUE", 5);

	player1.addWeapon(&weapon2);
	player2.addWeapon(&weapon3);
	player3.addWeapon(&weapon1);

	team1.addPlayer(&player1);
	team2.addPlayer(&player2);
	team2.addPlayer(&player3);

	player1.printInfoPlayer();
	player2.printInfoPlayer();
	player3.printInfoPlayer();

	return 0;
}