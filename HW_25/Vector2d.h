#pragma once
#include <iostream>
#include <string>
#include "VectorRelativeState.h"

class Vector2d {
private:
	float tailX, tailY;
	float headX, headY;

public:
	
	Vector2d(float x0, float y0, float x1, float y1);

	float dotProduct(const Vector2d& other) const;

	float crossProduct(const Vector2d& other) const;

	Vector2d negate() const;

	VectorRelativeState getRelativeState(const Vector2d& other) const;

	void scale(float factorX, float factorY);
};