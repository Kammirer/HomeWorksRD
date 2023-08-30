#include <string>
#include "Weapon.h"
#include "PlayerClass.h"
#include "Player.h"
#include "Team.h"

int main()
{
	//Game cycle
	Player player1("ASH", new AssaultRifle, new AttackerClass, new BlueTeam);
	Player player2("VALKYRIE", new Shotgun, new DefenderClass, new RedTeam);
	Player player3("KALI", new SniperRifle, new AttackerClass, new BlueTeam);
	Player player4("LESION", new Pistol, new DefaultClass, new RedTeam);

	player1.attack(player2, 500);
	player3.attack(player2, 1000);
	player1.attack(player3, 300);
	player2.attack(player1, 100);
	player1.healing(player1);
	player1.attack(player2, 200);
	player2.healing(player2);
	player4.attack(player3, 300);
	player1.healing(player1);
	player4.attack(player3, 100);
	player3.healing(player3);
	player1.attack(player3, 600);
	player1.attack(player4, 200);

	return 0;
}