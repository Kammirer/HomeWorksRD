#include <iostream>
#include <string>
#include <cmath>

class Rectangle {
private:
	float length;
	float height;

public:
	Rectangle() {
		length = 15;
		height = 7;

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

	float getArea() {
		return length * height;
	}

	float getPerimeter() {
		return  2 * (length + height);
	}
};

int Rectangle::rectangleCount = 0;

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
	Vector2d& operator=(const Vector2d vector) {
		x = vector.x;
		y = vector.y;
		return *this;
	}

	// operator +, -
	Vector2d operator+(const Vector2d& secondVector) {
		return Vector2d(x + secondVector.x, y + secondVector.y);
	}

	Vector2d operator-(const Vector2d& secondVector) {
		return Vector2d(x - secondVector.x, y - secondVector.y);
	}

	// friend +, -
	friend Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector);
	friend Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector);

	// operator ()()
	float operator()() {
		return std::sqrt(x * x + y * y);
	}

	// operator []
	float& operator[](int i) {
		if (i == 0) {
			return x;
		}
		else if (i == 1) {
			return y;
		}
	}

	// operator <<
	friend std::ostream& operator<<(std::ostream& out, Vector2d& vector);

	// operator >>
	friend std::istream& operator>>(std::istream& in, Vector2d& vector);
};

Vector2d operator+(const Vector2d& leftVector, const Vector2d& rightVector) {
	return Vector2d(leftVector.x + rightVector.x, leftVector.y + rightVector.y);
}

Vector2d operator-(const Vector2d& leftVector, const Vector2d& rightVector) {
	return Vector2d(leftVector.x - rightVector.x, leftVector.y - rightVector.y);
}

std::ostream& operator<<(std::ostream& out, Vector2d& vector) {
	out << "{" << vector.x << ";" << vector.y << "}";
	return out;
}

std::istream& operator>>(std::istream& in, Vector2d& vector) {
	in >> vector.x >> vector.y;
	return in;
}

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