#include "Rectangle.h"

float Rectangle::getArea() const {
	return length * height;
}

float Rectangle::getPerimeter() const {
	return  2 * (length + height);
}

int Rectangle::rectangleCount = 0;