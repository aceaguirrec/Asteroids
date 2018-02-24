#include "Asteroid.hpp"
#include "Palette.h"

//define window border constant values
const int windowBottom = -380.0f;
const int windowCeiling = 380.0f;
const int windowLeftBorder = -600.0f;
const int windowRightBorder = 600.0f;

//define asteroid movement speed
const float asteroidMovementSpd = 5.0f;

//define asteroid rotation speed
const float asteroidRotationSpd = 3.5f;

MathUtilities asteroidMaths;

using namespace std;

Asteroid::Asteroid(){

	SetAsteroidPoints();
}

void Asteroid::SetAsteroidPoints(void) {
	
		asteroidPts.push_back(Vector2(20.12282f, 60.62634f));
		asteroidPts.push_back(Vector2(10.06101f, 20.71695f));
		asteroidPts.push_back(Vector2(-30.76541f, 20.57216f));
		asteroidPts.push_back(Vector2(-60.0f, 60.0f));
		asteroidPts.push_back(Vector2(-30.54822f, 80.55691f));
	
}


void Asteroid::DrawAsteroid(void) {

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < asteroidPts.size(); i++) {

		glVertex2f(asteroidPts[i].x, asteroidPts[i].y);

	}
	glEnd();
}


void Asteroid::Update(void){

}

void Asteroid::Render(void){

	glLoadIdentity();
	

	Palette colors = Palette();
	Color bgColor = colors.getPurple();
	glClearColor(bgColor.getRed(), bgColor.getGreen(), bgColor.getBlue(), bgColor.getAlpha());

	DrawAsteroid();
}

float Asteroid::Warp(float asteroidCoordinate, float borderMinValue, float borderMaxValue){

	if (asteroidCoordinate < borderMinValue) {

		asteroidCoordinate = borderMaxValue + (borderMinValue - asteroidCoordinate);
		return asteroidCoordinate;
	}

	if (asteroidCoordinate > borderMaxValue) {

		asteroidCoordinate = borderMinValue - (asteroidCoordinate - borderMaxValue);
		return asteroidCoordinate;
	}

	return asteroidCoordinate;
}



