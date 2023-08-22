#include <iostream>
#include "Rectangle.h"
#include "Classification.h"
#include "Player.h"
#include "Weapon.h"
#include "Team.h"

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