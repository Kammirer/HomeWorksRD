#pragma once
#include <iostream>
#include <string>

class Vector2d {
private:
	float x;
	float y;

public:
	Vector2d(float x_par = 0.0, float y_par = 0.0) {
		x = x_par;
		y = y_par;
	}

	// operator =
	Vector2d& operator=(const Vector2d vector);

	// operator +, -
	Vector2d operator+(const Vector2d& secondVector);

	Vector2d operator-(const Vector2d& secondVector);

	// friend +, -
	friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
	friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);

	// operator ()()
	float operator()() const;

	// operator []
	float& operator[](int i);

	// operator <<
	friend std::ostream& operator<<(std::ostream& out, Vector2d& vector);

	// operator >>
	friend std::istream& operator>>(std::istream& in, Vector2d& vector);
};