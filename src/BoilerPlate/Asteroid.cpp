#include "Asteroid.hpp"
#include "Palette.h"

//define window border constant values
const int windowBottom = -380.0f;
const int windowCeiling = 380.0f;
const int windowLeftBorder = -600.0f;
const int windowRightBorder = 600.0f;


MathUtilities asteroidMaths;

using namespace std;

Asteroid::Asteroid(float entityWidth, float entityHeight){

	asteroidPosition = new Vector2(rand(), rand());
	Entity(entityWidth, entityHeight);
	asteroidSize = 3;
	SetAsteroidPoints();
}

Asteroid::Asteroid(asteroidType type){

	asteroidSize = type;
	SetAsteroidPoints();
}

void Asteroid::SetAsteroidPoints(void) {
		
	int asteroidSizeFactor = GetAsteroidSize();
	
	asteroidPts.push_back(Vector2((20.12282f * asteroidSizeFactor), (60.62634f* asteroidSizeFactor)));
	asteroidPts.push_back(Vector2((10.06101f * asteroidSizeFactor), (20.71695f * asteroidSizeFactor)));
	asteroidPts.push_back(Vector2((-30.76541f * asteroidSizeFactor), (20.57216f * asteroidSizeFactor)));
	asteroidPts.push_back(Vector2((-60.0f * asteroidSizeFactor), (60.0f * asteroidSizeFactor)));
	asteroidPts.push_back(Vector2((-30.54822f * asteroidSizeFactor), (80.55691f * asteroidSizeFactor)));
	
}


void Asteroid::DrawAsteroid(void) {

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < asteroidPts.size(); i++) {

		glVertex2f(asteroidPts[i].x, asteroidPts[i].y);

	}
	glEnd();
}

int Asteroid::GetAsteroidSize(void){

	return asteroidSize;
}

void Asteroid::AsteroidImpulse(void){

	entityVelocity->x = (asteroidMovementSpd / entityMass) * (-sinf(asteroidMaths.degsToRads(asteroidOrientationAngle))) + asteroidSize;
	entityVelocity->y = (asteroidMovementSpd / entityMass) * cosf(asteroidMaths.degsToRads(asteroidOrientationAngle)) + asteroidSize;
}

void Asteroid::GenerateAsteroidOrientationAngle(void){

	asteroidOrientationAngle = (rand() % 360);
}



void Asteroid::Update(float deltaTime){

	entityPosition->x += (entityVelocity->x * deltaTime);
	entityPosition->y += (entityVelocity->y * deltaTime);

	entityPosition->x = Warp(entityPosition->x, entityMinWidth, entityMaxWidth);
	entityPosition->y = Warp(entityPosition->y, entityMinHeight, entityMaxHeight);

	asteroidOrientationAngle += (asteroidRotationSpd * deltaTime);
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



