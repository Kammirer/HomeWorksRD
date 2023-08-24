#pragma once

class Rectangle {
private:
	float length;
	float height;

public:
	Rectangle() {
		length = 0.0;
		height = 0.0;

		rectangleCount++;
	}

	Rectangle(float length_par, float height_par) {
		length = length_par;
		height = height_par;

		rectangleCount++;
	}

	~Rectangle() {
		rectangleCount--;
	}

	static int rectangleCount;

	float getArea() const;

	float getPerimeter() const;
};