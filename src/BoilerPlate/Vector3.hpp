#pragma once

#ifndef VECTOR3_H
#define VECTOR3_H
#include "Vector2.hpp"

struct Vector3 {

	/*==============================
	* Members
	*==============================*/
	float x, y, z;
	float length;


	/*==============================
	* Constructors
	*==============================*/
	Vector3();
	Vector3(float x_axis, float y_axis, float z_axis);
	Vector3(float axes);
	Vector3(const Vector2&);



	/*==============================
	* Length functions
	*==============================*/
	float vLength() const;
	float squaredLength() const;
	float normalize();

	/*==============================
	* Overloaded Operators
	*==============================*/
	Vector3& operator =(const Vector3& rhs);
	Vector3 operator +(const Vector3& rhs);
	Vector3 operator -(const Vector3& rhs);
	Vector3 operator *(const Vector3& rhs);
	Vector3 operator /(const Vector3& rhs);
	Vector3& operator +=(const Vector3& rhs);
	Vector3& operator -=(const Vector3& rhs);
	Vector3& operator *=(const Vector3& rhs);
	Vector3& operator /=(const Vector3& rhs);
	bool	 operator ==(const Vector3& rhs);
	bool	 operator !=(const Vector3& rhs);
	friend Vector3& operator *(float n, const Vector3& rhs);
	friend Vector3& operator *(const Vector3& lhs, float n);
};
#endif // !VECTOR3_H_