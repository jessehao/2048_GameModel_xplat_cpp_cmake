#include "Vector2.h"
#include <cmath>

#pragma region Static Constants
const Vector2& Vector2::ZERO = Vector2(0, 0);
const Vector2& Vector2::ONE = Vector2(1, 1);
const Vector2& Vector2::UP = Vector2(0, 1);
const Vector2& Vector2::DOWN = Vector2(0, -1);
const Vector2& Vector2::LEFT = Vector2(-1, 0);
const Vector2& Vector2::RIGHT = Vector2(1, 0);
#pragma endregion

#pragma region Static Methods
double Vector2::dot(const Vector2& vec1, const Vector2& vec2) {
	return vec1.x * vec2.x + vec1.y * vec2.y;
}
#pragma endregion

#pragma region Methods
bool Vector2::isVertical() {
	return this->x == 0 && this->y != 0;
}

bool Vector2::isHorizontal() {
	return this->x != 0 && this->y == 0;
}

double Vector2::getMagnitude() {
	return sqrt(getSqrMagnitude());
}

double Vector2::getSqrMagnitude() {
	return pow(this->x, 2) + pow(this->y, 2);
}

Vector2* Vector2::getNormalized() {
	double mag = getMagnitude();
	if (mag == 0) return new Vector2();
	return new Vector2(this->x / mag, this->y / mag);
}

void Vector2::normalize() {
	double mag = getMagnitude();
	if (mag == 0) return;
	this->x /= mag;
	this->y /= mag;
}

void Vector2::set(double x, double y) {
	this->x = x;
	this->y = y;
}

Vector2* Vector2::getCopy() {
	return new Vector2(*this);
}
#pragma endregion

#pragma region Operators
bool Vector2::operator==(const Vector2& vec) {
	return this->x == vec.x && this->y == vec.y;
}

bool operator==(const Vector2& left, const Vector2& right) {
	return left.x == right.x && left.y == right.y;
}

Vector2* operator+(const Vector2& left, const Vector2& right) {
	return new Vector2(left.x + right.x, left.y + right.y);
}

Vector2* operator-(const Vector2& left, const Vector2& right) {
	return new Vector2(left.x - right.x, left.y - right.y);
}

double Vector2::operator[](int index) {
	return index == 0 ? this->x : this->y;
}

void Vector2::operator+=(Vector2& vec) {
	set(this->x + vec.x, this->y + vec.y);
}

void Vector2::operator-=(Vector2& vec) {
	set(this->x - vec.x, this->y - vec.y);
}
#pragma endregion

#pragma region Constructor & Destructor
Vector2::Vector2() : x(0), y(0) {}

Vector2::Vector2(const Vector2& vec) : x(vec.x), y(vec.y) {}

Vector2::Vector2(const Vector2* vec) : x(vec->x), y(vec->y) {}
Vector2::Vector2(double x, double y) : x(x), y(y) {}

Vector2::~Vector2() {}
#pragma endregion
