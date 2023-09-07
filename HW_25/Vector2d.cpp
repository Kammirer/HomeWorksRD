#include "Vector2d.h"

Vector2d::Vector2d(float x0, float y0, float x1, float y1) {
	tailX = x0;
	tailY = y0;
	headX = x1;
	headY = y1;
}

float Vector2d::dotProduct(const Vector2d& other) const {
    float dx = headX - tailX;
    float dy = headY - tailY;

    float other_dx = other.headX - other.tailX;
    float other_dy = other.headY - other.tailY;

    return (dx * other_dx) + (dy * other_dy);
}

float Vector2d::crossProduct(const Vector2d& other) const {
    float dx1 = headX - tailX;
    float dy1 = headY - tailY;

    float dx2 = other.headX - other.tailX;
    float dy2 = other.headY - other.tailY;

    return (dx1 * dy2 - dy1 * dx2);
}

Vector2d Vector2d::negate() const {
    return Vector2d(headX, headY, tailX, tailY);
}

VectorRelativeState Vector2d::getRelativeState(const Vector2d& other) const {
    float dx1 = headX - tailX;
    float dy1 = headY - tailY;

    float dx2 = other.headX - other.tailX;
    float dy2 = other.headY - other.tailY;

    float length1 = std::sqrt(dx1 * dx1 + dy1 * dy1);
    float length2 = std::sqrt(dx2 * dx2 + dy2 * dy2);

    float dotProduct = dx1 * dx2 + dy1 * dy2;

    float cosAngle = dotProduct / (length1 * length2);

    if (cosAngle == 1.0f) {
        return VectorRelativeState::Identical;
    }
    else if (cosAngle == -1.0f) {
        return VectorRelativeState::OppositeDirected;
    }
    else if (cosAngle < 0.0f) {
        return VectorRelativeState::ObtuseAngle;
    }
    else if (cosAngle == 0.0f) {
        return VectorRelativeState::RightAngle;
    }
    else {
        return VectorRelativeState::AcuteAngle;
    }
}

void Vector2d::scale(float factorX, float factorY) {
    tailX *= factorX;
    tailY *= factorY;
    headX *= factorX;
    headY *= factorY;
}