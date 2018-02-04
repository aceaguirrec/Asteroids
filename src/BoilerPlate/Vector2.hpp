#pragma once


struct Vector2 {

	/*==============================
	* Members
	*==============================*/
	float x;
	float y;
	float length;


	/*==============================
	* Constructors
	*==============================*/
	Vector2();
	Vector2(float x_axis, float y_axis);
	Vector2(float axes);



	/*==============================
	* Functions
	*==============================*/
	float vLength() const;
	float squaredLength() const;
	float normalize();


	/*==============================
	* Overloaded Operators
	*==============================*/
	Vector2& operator =(const Vector2& rhs);
	Vector2 operator +(const Vector2& rhs);
	Vector2 operator -(const Vector2& rhs);
	Vector2 operator *(const Vector2& rhs);
	Vector2 operator /(const Vector2& rhs);
	Vector2& operator +=(const Vector2& rhs);
	Vector2& operator -=(const Vector2& rhs);
	Vector2& operator *=(const Vector2& rhs);
	Vector2& operator /=(const Vector2& rhs);
	bool	 operator ==(const Vector2& rhs);
	bool	 operator !=(const Vector2& rhs);
	friend Vector2& operator *(float n, const Vector2& rhs);
	friend Vector2& operator *(const Vector2& lhs, float n);

};