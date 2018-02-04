#include "Vector3.hpp"
#include <cmath>

Vector3::Vector3(){

	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	length = 0.0f;
}

Vector3::Vector3(float x_axis, float y_axis, float z_axis){

	x = x_axis;
	y = y_axis;
	z = z_axis;
	length = vLength();
}

Vector3::Vector3(float axes){

	x = axes;
	y = axes;
	z = axes;
	length = vLength();
}

Vector3::Vector3(const Vector2 & v){

	x = v.x;
	y = v.y;
	z = 0.0f;
	length = vLength();
}

float Vector3::vLength() const{

	float vectorLength;
	vectorLength = sqrt(pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0));

	return vectorLength;
}

float Vector3::squaredLength() const{

	float vectorLength;
	vectorLength = (pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0));

	return vectorLength;
}

float Vector3::normalize(){

	float inverse = 1.0f / length;
	vLength();

	x *= inverse;
	y *= inverse;
	z *= inverse;

	return length;
}

Vector3 & Vector3::operator=(const Vector3 & rhs){

	x = rhs.x;
	y = rhs.y;
	z = rhs.z;

	return *this;
}

Vector3 Vector3::operator+(const Vector3 & rhs){

	float xAx, yAx, zAx;
	xAx = x + rhs.x;
	yAx = y + rhs.y;
	zAx = z + rhs.z;

	return Vector3(xAx, yAx, zAx);
}

Vector3 Vector3::operator-(const Vector3 & rhs){

	float xAx, yAx, zAx;
	xAx = x - rhs.x;
	yAx = y - rhs.y;
	zAx = z - rhs.z;

	return Vector3(xAx, yAx, zAx);
}

Vector3 Vector3::operator*(const Vector3 & rhs){
	
	float xAx, yAx, zAx;
	xAx = x * rhs.x;
	yAx = y * rhs.y;
	zAx = z * rhs.z;

	return Vector3(xAx, yAx, zAx);
}

Vector3 Vector3::operator/(const Vector3 & rhs){
	float xAx, yAx, zAx;

	if (rhs.x == 0) throw "Division by 0 is not defined.";
	if (rhs.y == 0) throw "Division by 0 is not defined.";
	if (rhs.z == 0) throw "Division by 0 is not defined.";

	xAx = x / rhs.x;
	yAx = y / rhs.y;
	zAx = z / rhs.z;

	return Vector3(xAx, yAx, zAx);
}

Vector3 & Vector3::operator+=(const Vector3 & rhs){

	x += rhs.x;
	y += rhs.y;
	z += rhs.z;

	return *this;
}

Vector3 & Vector3::operator-=(const Vector3 & rhs){

	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;

	return *this;
}

Vector3 & Vector3::operator*=(const Vector3 & rhs){

	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;

	return *this;
}

Vector3 & Vector3::operator/=(const Vector3 & rhs){

	if (rhs.x == 0) throw "Division by 0 is not defined.";
	if (rhs.y == 0) throw "Division by 0 is not defined.";
	if (rhs.z == 0) throw "Division by 0 is not defined.";

	x /= rhs.x;
	y /= rhs.y;
	z /= rhs.z;

	return *this;
}

bool Vector3::operator==(const Vector3 & rhs){

	bool result;

	if (x == rhs.x && y == rhs.y && z == rhs.z)
		result = true;
	else
		result = false;

	return result;
}

bool Vector3::operator!=(const Vector3 & rhs){

	bool result;

	if (x != rhs.x || y != rhs.y || z != rhs.z)
		result = true;
	else
		result = false;

	return result;
}

Vector3 & operator*(float n, const Vector3 & rhs){
	float xAx, yAx, zAx;

	xAx = n * rhs.x;
	yAx = n * rhs.y;
	zAx = n * rhs.z;

	return Vector3(xAx, yAx, zAx);
}

Vector3 & operator*(const Vector3 & lhs, float n){
	
	float xAx, yAx, zAx;

	xAx = n * lhs.x;
	yAx = n * lhs.y;
	zAx = n * lhs.z;

	return Vector3(xAx, yAx, zAx);
}
