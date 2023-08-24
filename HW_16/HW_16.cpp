#include <iostream>
#include <string>
#include <cmath>

#include "Rectangle.h"
#include "Vector2d.h"

int main()
{
	// Step 1 - Rectangle - static
	Rectangle rect1;
	std::cout << "Rectangle count: " << rect1.rectangleCount << std::endl; // 1
	Rectangle rect2(8, 3);
	std::cout << "Rectangle count: " << rect2.rectangleCount << std::endl; // 2
	{
		Rectangle rect3(11, 5);
		std::cout << "Rectangle count: " << rect2.rectangleCount << std::endl; // 3
	}
	std::cout << "Rectangle count: " << rect2.rectangleCount << std::endl; // 2

	std::cout << std::endl;

	// Step 2 - Vector2d
	Vector2d vector1(4.5, 1.3);
	std::cout << vector1 << std::endl;

	Vector2d vector2;
	std::cout << "Enter vector x y: ";
	std::cin >> vector2;
	std::cout << vector2 << std::endl;

	float lengthVec = vector2();
	std::cout << lengthVec << std::endl;

	Vector2d vector3;
	vector3[0] = 15;
	std::cout << vector3 << std::endl;

	return 0;
}