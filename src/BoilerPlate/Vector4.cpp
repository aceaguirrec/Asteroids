#include "Vector4.hpp"
#include <cmath>


/*=================
* Constructors
=================*/
Vector4::Vector4(){

	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
	length = 0.0f;
}

Vector4::Vector4(float x_axis, float y_axis, float z_axis, float w_axis){

	x = x_axis;
	y = y_axis;
	z = z_axis;
	w = w_axis;
	length = vLength();
}

Vector4::Vector4(float axes){

	x = axes;
	y = axes;
	z = axes;
	w = axes;
	length = vLength();
}

Vector4::Vector4(const Vector3 & v){

	x = v.x;
	y = v.y;
	z = v.z;
	w = 0.0f;
	length = vLength();
}


/*=================
* Length functions
=================*/
float Vector4::vLength() const{

	float vectorLength;
	vectorLength = sqrt(pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0) + pow(w, 2.0));

	return vectorLength;
}

float Vector4::squaredLength() const{

	float sqLength;
	sqLength = (pow(x, 2.0) + pow(y, 2.0) + pow(z, 2.0) + pow(w, 2.0));

	return sqLength;
}

float Vector4::normalize(){

	float inverse = 1.0f / length;
	vLength();

	x *= inverse;
	y *= inverse;
	z *= inverse;
	w *= inverse;

	return length;
}


/*==============================
* Overloaded operators
*==============================*/
Vector4 & Vector4::operator=(const Vector4 & rhs){

	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = rhs.w;

	return *this;
}

Vector4 Vector4::operator+(const Vector4 & rhs){

	float xAx, yAx, zAx, wAx;
	xAx = x + rhs.x;
	yAx = y + rhs.y;
	zAx = z + rhs.z;
	wAx = w + rhs.w;

	return Vector4(xAx, yAx, zAx, wAx);
}

Vector4 Vector4::operator-(const Vector4 & rhs){

	float xAx, yAx, zAx, wAx;
	xAx = x - rhs.x;
	yAx = y - rhs.y;
	zAx = z - rhs.z;
	wAx = w - rhs.w;

	return Vector4(xAx, yAx, zAx, wAx);
}

Vector4 Vector4::operator*(const Vector4 & rhs){

	float xAx, yAx, zAx, wAx;
	xAx = x * rhs.x;
	yAx = y * rhs.y;
	zAx = z * rhs.z;
	wAx = w * rhs.w;

	return Vector4(xAx, yAx, zAx, wAx);
}

Vector4 Vector4::operator/(const Vector4 & rhs){

	float xAx, yAx, zAx, wAx;

	if (rhs.x == 0) throw "Division by 0 is not defined.";
	if (rhs.y == 0) throw "Division by 0 is not defined.";
	if (rhs.z == 0) throw "Division by 0 is not defined.";
	if (rhs.w == 0) throw "Division by 0 is not defined.";

	xAx = x / rhs.x;
	yAx = y / rhs.y;
	zAx = z / rhs.z;
	wAx = w / rhs.w;

	return Vector4(xAx, yAx, zAx, wAx);
}

Vector4 & Vector4::operator+=(const Vector4 & rhs){

	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;

	return *this;
}

Vector4 & Vector4::operator-=(const Vector4 & rhs){

	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;

	return *this;
}

Vector4 & Vector4::operator*=(const Vector4 & rhs){

	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	w *= rhs.w;

	return *this;
}

Vector4 & Vector4::operator/=(const Vector4 & rhs){

	if (rhs.x == 0) throw "Division by 0 is not defined.";
	if (rhs.y == 0) throw "Division by 0 is not defined.";
	if (rhs.z == 0) throw "Division by 0 is not defined.";
	if (rhs.w == 0) throw "Division by 0 is not defined.";

	x /= rhs.x;
	y /= rhs.y;
	z /= rhs.z;
	w /= rhs.w;

	return *this;
}

bool Vector4::operator==(const Vector4 & rhs){

	bool result;

	if (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w)
		result = true;
	else
		result = false;

	return result;
}

bool Vector4::operator!=(const Vector4 & rhs){

	bool result;

	if (x != rhs.x || y != rhs.y || z != rhs.z || w != rhs.w)
		result = true;
	else
		result = false;

	return result;
}

Vector4 & operator*(float n, const Vector4 & rhs){

	float xAx, yAx, zAx, wAx;

	xAx = n * rhs.x;
	yAx = n * rhs.y;
	zAx = n * rhs.z;
	wAx = n * rhs.w;

	return Vector4(xAx, yAx, zAx, wAx);
}

Vector4 & operator*(const Vector4 & lhs, float n){


	float xAx, yAx, zAx, wAx;

	xAx = n * lhs.x;
	yAx = n * lhs.y;
	zAx = n * lhs.z;
	wAx = n * lhs.w;

	return Vector4(xAx, yAx, zAx, wAx);
}
