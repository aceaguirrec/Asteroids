#include "MathUtilities.h"
#include "math.h"

int MathUtilities::nearestInt(float x){
	return nearbyint(x);
}

int MathUtilities::nearestEvenInt(float x){
	int nearestEvenInt = (round(x/2.0)) * 2.0;
	return nearestEvenInt;
}

double MathUtilities::degsToRads(double angle){
	return ((angle * 3.14159)/180);
}

double MathUtilities::radsToDegs(double angle){
	return ((angle * 180)/3.14159);
}

double MathUtilities::angDistDegs(double angle_a, double angle_b){
	double angDistance = (angle_a - angle_b);

	if (angDistance < 0) angDistance += 360.0;

	return angDistance;
}

double MathUtilities::angDistRads(double angle_a, double angle_b){
	double angDistance = (angle_a - angle_b);

	if (angDistance < 0) angDistance += (3.14159 * 2.0);

	return angDistance;
}

bool MathUtilities::isPowerOfTwo(int n){
	while ((n % 2 == 0) && n > 1)
		n /= 2;

	return (n == 1);
}
