#pragma once

#ifndef MATHUTILITIES_H
#define MATHUTILITIES_H


class MathUtilities {
public:

	float const Pi = 3.14159265; //constant representing Pi

	int nearestInt(float x); //gets nearest integer to a float

	int nearestEvenInt(float x); //gets nearest even integer to a float

	/*gets the maximum between 
	2, 3 or 4 given values*/
	template <class num> 
	num getMax(num x, num y) {
		return (x > y ? x : b);
	}

	template <class num> 
	num getMax(num x, num y, num z) {
		if (x > y && x > z) return x;

		if (y > x && y > z) return y;

		if (z > x && z > y) return z;

		if (x == y && x == z) return NULL;
	}

	template <class num> 
	num getMax(num x, num y, num z, num a) {
		if (x > y && x > z && x > a) return x;

		if (y > x && y > z && y > a) return y;

		if (a > x && a > y && a > z) return a;

		if (x == y && x == z && x == a) return NULL;
	
	}

	/*gets the minimum between
	2, 3 or 4 given values*/
	template <class num> 
	num getMin(num x, num y) {
		return (x < y ? x : y);
	}

	template <class num> 
	num getMin(num x, num y, num z) {
		if (x < y && x < z) return x;

		if (y < x && y < z) return y;

		if (z < x && z < y) return z;

		if (x == y && x == z) return NULL;
	}

	template <class num> 
	num getMin(num x, num y, num z, num a) {
		if (x < y && x < z && x < a) return x;

		if (y < x && y < z && y < a) return y;

		if (a < x && a < y && a < z) return a;

		if (x == y && x == z && x == a) return NULL;
	}

	/*converts angles given in degrees to radians
	and viceversa*/
	double degsToRads(double angle);
	double radsToDegs(double angle);

	/*calculates angular distance between two angles
	given in both degrees and radians*/
	double angDistDegs(double angle_a, double angle_b);
	double angDistRads(double angle_a, double angle_b);

	bool isPowerOfTwo(int n); //checks if a given integer is a power of 2

	/* interpolates a float (or an int) 
	between a start value and an end value, 
	at a fraction specified from start (0.0) to end (1.0)*/
	template <class num>
	num interpolate(num startVal, num endVal, num fraction) {
		return startVal + (endVal - startVal) * fraction;
	}

	/*clamps a float (or an int)
	to be within a specified range*/
	template <class num>
	num clampValue(num x, num min, num max) {
		if (x < min) x = min;

		if (x > max) x = max;


		return x;
	}

};
#endif // !MATHUTILITIES_H