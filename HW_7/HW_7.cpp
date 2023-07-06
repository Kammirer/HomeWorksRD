#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::cout << "HELLO, LEATHER BAG!\n" << "I`M A GAME =GUESS THE NUMBER=\n";
	std::cout << "\nSO! I GUESS A NUMBER FROM 0 TO 100 AND YOU GUESS IT, OK?!";
	std::cout << "\nIF YOU ARE FEARED OR TIRED ENTER -1 TO END!";
	std::cout << "\nLET`S TEST YOUR LUCK!";
	std::cout << std::endl << std::endl;

	int randNumber = 0;
	int steps = 0;
	int bestSteps = 0;
	
	srand(time(nullptr));
	randNumber = rand() % (100 + 1);

	std::cout << "Enter your number: ";

	while (true) {
		int inputNumber = 0;
		std::cin >> inputNumber;

		if (inputNumber == -1) {
			std::cout << "\nOH... I DIDN`T THINK YOU`D GIVE UP SO FAST...";
			std::cout << "\nCOME BACK! I WILL WAIT FOR YOU <3";
			break;
		}

		steps++;

		if (inputNumber < 0 || inputNumber > 100) {
			std::cout << "WOW-WOW... Do you want to fly into space?\nRead my condition and enter the correct number: ";
		}
		else {
			if (inputNumber == randNumber) {
				if ((bestSteps == 0) || (steps < bestSteps)) {
					bestSteps = steps;
				}

				if (steps == 1) {
					std::cout << "\nOH MY GOD! YOU ARE AMAZING!\n" << "YOUR CURRENT STEPS: " << steps << "\nYOUR BEST STEPS: " << bestSteps << std::endl << std::endl << std::endl;
					std::cout << "\nLET`S DO THIS AGAIN!\nEnter your number: ";
				}
				else {
					std::cout << "\nCONGRATULATION!\n" << "YOUR CURRENT STEPS: " << steps << "\nYOUR BEST STEPS: " << bestSteps << std::endl << std::endl << std::endl;
					std::cout << "\nLET`S DO THIS AGAIN!\nEnter your number: ";
				}

				steps = 0;
				srand(time(nullptr));
				randNumber = rand() % (100 + 1);

			}
			else if (inputNumber > randNumber) {

				if ((inputNumber - randNumber) <= 10) {
					std::cout << "YOU ARE SO CLOSE. Enter a number slightly SMALLER than the previous: ";
				}
				else if ((inputNumber - randNumber) > 10 && (inputNumber - randNumber) <= 30) {
					std::cout << "OH... My number is SMALLER! Try it again: ";
				}
				else if ((inputNumber - randNumber) > 30 && (inputNumber - randNumber) <= 60) {
					std::cout << "GOOD LUCK! My number is SO SMALLER! Enter number again: ";
				}
				else if ((inputNumber - randNumber) > 60) {
					std::cout << "LOOOSEEER! Your grandmother plays this game better than you! Try LESS: ";
				}

			}
			else if (inputNumber < randNumber) {

				if ((randNumber - inputNumber) <= 10) {
					std::cout << "YOU ARE SO CLOSE. Enter a number slightly BIGGER than the previous: ";
				}
				else if ((randNumber - inputNumber) > 10 && (randNumber - inputNumber) <= 30) {
					std::cout << "GOOD, BUT... My number is BIGGER! Try it again: ";
				}
				else if ((randNumber - inputNumber) > 30 && (randNumber - inputNumber) <= 60) {
					std::cout << "HA-HA-HA... My number is SO BIGGER! Enter number again: ";
				}
				else if ((randNumber - inputNumber) > 60) {
					std::cout << "LOOOSEEER! Your grandmother plays this game better than you! Try HIGHER: ";
				}

			}
		}
	}

	std::cout << std::endl << std::endl;

	return 0;
}