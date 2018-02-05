#include "Vector2.hpp"
#include <cmath>


/*=================
* Constructors
=================*/
Vector2::Vector2(){
	
	x = 0.0f;
	y = 0.0f;
	length = 0.0f;

}

Vector2::Vector2(float x_axis, float y_axis){
	
	x = x_axis;
	y = y_axis;
	length = 0.0f;

	vLength();

}

Vector2::Vector2(float axes){
	
	x = axes;
	y = axes;
	length = 0.0f;

	vLength();

}

/*=================
* Length functions
=================*/
float Vector2::vLength() const{
	
	float vectorLength;
	vectorLength = sqrt(pow(x, 2.0) + pow(y, 2.0));

	return vectorLength;
}

float Vector2::squaredLength() const{
	
	float sqLength;
	sqLength = (pow(x, 2.0) + pow(y, 2.0));

	return sqLength;
}

float Vector2::normalize(){

	vLength();

	float inverse = 1.0f / length;
	x *= inverse;
	y *= inverse;


	return length;
}

/*=================
* Overloaded operators
=================*/
Vector2 & Vector2::operator=(const Vector2 & rhs){
	
	x = rhs.x;
	y = rhs.y;

	return *this;
}

Vector2 Vector2::operator+(const Vector2 & rhs){

	float xAx, yAx;
	xAx = x + rhs.x;
	yAx = y + rhs.y;

	return Vector2(xAx, yAx);
}

Vector2 Vector2::operator-(const Vector2 & rhs) {

	float xAx, yAx;
	xAx = x - rhs.x;
	yAx = y - rhs.y;

	return Vector2(xAx, yAx);
}

Vector2 Vector2::operator*(const Vector2 & rhs) {

	float xAx, yAx;
	xAx = x * rhs.x;
	yAx = y * rhs.y;

	return Vector2(xAx, yAx);
}

Vector2 Vector2::operator/(const Vector2 & rhs) {

	float xAx, yAx;

	if (rhs.x == 0) throw "Division by 0 is not defined.";
	if (rhs.y == 0) throw "Division by 0 is not defined.";

	xAx = x / rhs.x;
	yAx = y / rhs.y;

	return Vector2(xAx, yAx);
}

Vector2 & Vector2::operator+=(const Vector2 & rhs){

	x += rhs.x;
	y += rhs.y;

	return *this;
}


Vector2 & Vector2::operator-=(const Vector2 & rhs){
	
	x -= rhs.x;
	y -= rhs.y;

	return *this;
}

Vector2 & Vector2::operator*=(const Vector2 & rhs){
	
	x *= rhs.x;
	y *= rhs.y;

	return *this;
}

Vector2 & Vector2::operator/=(const Vector2 & rhs){

	if (rhs.x == 0) throw "Division by 0 is not defined.";
	if (rhs.y == 0) throw "Division by 0 is not defined.";

	x /= rhs.x;
	y /= rhs.y;

	return *this;
}

bool Vector2::operator==(const Vector2 & rhs){
	
	bool result;

	if (x == rhs.x && y == rhs.y) 
		result = true;
	else
		result = false;

	return result;
}

bool Vector2::operator!=(const Vector2 & rhs){

	bool result;

	if (x != rhs.x || y != rhs.y)
		result = true;
	else
		result = false;
	
	return result;
}

Vector2 & operator*(float n, const Vector2 & rhs){

	float xAx, yAx;

	xAx = n * rhs.x;
	yAx = n * rhs.y;

	return Vector2(xAx, yAx);
	
}

Vector2 & operator*(const Vector2 & lhs, float n){
	
	float xAx, yAx;

	xAx = n * lhs.x;
	yAx = n * lhs.y;

	return Vector2(xAx, yAx);
}