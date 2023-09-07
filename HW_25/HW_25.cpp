#include <iostream>
#include <string>
#include <cmath>

#include "Vector2d.h"
#include "VectorRelativeState.h"

int main()
{
	Vector2d myVector_1(1.2, 2.1, 5.1, 7.2);
	Vector2d myVector_2(1.7, 1.3, 0.7, 2.2);

	myVector_1.crossProduct(myVector_2);

	Vector2d myVector_3 = myVector_2.negate();

	myVector_3.scale(1.0, 0.5);

	return 0;
}