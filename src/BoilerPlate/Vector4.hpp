#pragma once
#include "Vector2.hpp"
#include "Vector3.hpp"

struct Vector4 {

	/*==============================
	* Members
	*==============================*/
	float x, y, z, w;
	float length;


	/*==============================
	* Constructors
	*==============================*/
	Vector4();
	Vector4(float x_axis, float y_axis, float z_axis, float w_axis);
	Vector4(float axes);
	Vector4(const Vector3&);


	/*==============================
	* Length functions
	*==============================*/
	float vLength() const;
	float squaredLength() const;
	float normalize();


	/*==============================
	* Overloaded operators
	*==============================*/
	Vector4& operator =(const Vector4& rhs);
	Vector4 operator +(const Vector4& rhs);
	Vector4 operator -(const Vector4& rhs);
	Vector4 operator *(const Vector4& rhs);
	Vector4 operator /(const Vector4& rhs);
	Vector4& operator +=(const Vector4& rhs);
	Vector4& operator -=(const Vector4& rhs);
	Vector4& operator *=(const Vector4& rhs);
	Vector4& operator /=(const Vector4& rhs);
	bool	 operator ==(const Vector4& rhs);
	bool	 operator !=(const Vector4& rhs);
	friend Vector4& operator *(float n, const Vector4& rhs);
	friend Vector4& operator *(const Vector4& lhs, float n);
};