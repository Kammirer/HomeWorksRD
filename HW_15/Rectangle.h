#pragma once
#pragma once

class Rectangle {
public:
	Rectangle() {
		length = 1.0;
		height = 1.0;
	}

	Rectangle(float length_par, float height_par) {
		length = length_par;
		height = height_par;
	}

	float getArea() const;
	float getPerimeter() const;

private:
	float length;
	float height;
};