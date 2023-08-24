#include "Vector2d.h"

Vector2d& Vector2d::operator=(const Vector2d vector) {
	x = vector.x;
	y = vector.y;
	return *this;
}

Vector2d Vector2d::operator+(const Vector2d& secondVector) {
	return Vector2d(x + secondVector.x, y + secondVector.y);
}

Vector2d Vector2d::operator-(const Vector2d& secondVector) {
	return Vector2d(x - secondVector.x, y - secondVector.y);
}

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector) {
	return Vector2d(leftVector.x + rightVector.x, leftVector.y + rightVector.y);
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector) {
	return Vector2d(leftVector.x - rightVector.x, leftVector.y - rightVector.y);
}

float Vector2d::operator()() const {
	return std::sqrt(x * x + y * y);
}

float& Vector2d::operator[](int i) {
	if (i == 0) {
		return x;
	}
	else if (i == 1) {
		return y;
	}

std::ostream& operator<<(std::ostream& out, Vector2d& vector) {
	out << "{" << vector.x << ";" << vector.y << "}";
	return out;
}

std::istream& operator>>(std::istream& in, Vector2d& vector) {
	in >> vector.x >> vector.y;
	return in;
}