#include "Asteroid.hpp"
#include "Palette.h"

MathUtilities asteroidMaths;

using namespace std;

Asteroid::Asteroid(float entityWidth, float entityHeight, int size){

	entityPosition = Vector2(rand(), rand());
	Entity(entityWidth, entityHeight);
	asteroidSize = 1;
	hasBeenImpacted = false;
	GenerateAsteroidOrientationAngle();
	SetAsteroidPoints();

	if (size == 1) entityRadius = 15;
	if (size == 2) entityRadius = 30;
	if (size == 3) entityRadius = 50;
}


void Asteroid::SetAsteroidPoints(void) {
		
	
	asteroidPts.push_back(Vector2(20.12282f, (60.62634f)));
	asteroidPts.push_back(Vector2(10.06101f, (20.71695f)));
	asteroidPts.push_back(Vector2(-30.76541f, (20.57216f)));
	asteroidPts.push_back(Vector2(-60.0f, (60.0f)));
	asteroidPts.push_back(Vector2(-30.54822f, (80.55691f)));
	
}


void Asteroid::DrawAsteroid(void) {

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);

	switch (asteroidSize) {
	case 1:
		for (int i = 0; i < asteroidPts.size(); i++) {

			glVertex2f((asteroidPts[i].x * 0.8f), (asteroidPts[i].y * 0.8f));
		}
		entityMass = 1.0f;
		break;

	case 2:
		for (int i = 0; i < asteroidPts.size(); i++) {

			glVertex2f(asteroidPts[i].x, asteroidPts[i].y);
		}
		entityMass = 2.0f;
		break;
	
	case 3:
		for (int i = 0; i < asteroidPts.size(); i++) {

			glVertex2f((asteroidPts[i].x * 2.0f), (asteroidPts[i].y * 2.0f));
		}
		entityMass = 3.0f;
		break;
	
	}
	
	glEnd();
}

Vector2 Asteroid::GetAsteroidPosition(void){

	return entityPosition;
}

int Asteroid::GetAsteroidSize(void){

	return asteroidSize;
}

void Asteroid::AsteroidImpulse(void){

	entityVelocity.x = (asteroidMovementSpd / entityMass) * (-sinf(asteroidMaths.degsToRads(entityOrientationAngle))) + asteroidSize;
	entityVelocity.y = (asteroidMovementSpd / entityMass) * cosf(asteroidMaths.degsToRads(entityOrientationAngle)) + asteroidSize;
}

void Asteroid::Collision(Player p1){

	float distanceToPlayer = GetDistanceBtwn2Entities((p1.GetEntityPosition));

	if (distanceToPlayer <= (entityRadius + p1.GetEntityRadius)) {

		isColliding = true;
		p1.SetCollidingStatus(true);
	}
}

void Asteroid::GenerateAsteroidOrientationAngle(void){

	entityOrientationAngle = (rand() % 360);
}



void Asteroid::Update(float deltaTime){
	
	if (asteroidSize == 1) asteroidMovementSpd = 3.5f;
	if (asteroidSize == 2) asteroidMovementSpd = 4.0f;
	if (asteroidSize == 3) asteroidMovementSpd = 4.5f;

	entityPosition.x += (asteroidMovementSpd * cosf(asteroidMaths.degsToRads(entityOrientationAngle)));
	entityPosition.y += (asteroidMovementSpd * sinf(asteroidMaths.degsToRads(entityOrientationAngle)));

	entityPosition.x = Warp(entityPosition.x, (entityWidth / 2.0f), ((-1.0f * entityWidth) / 2.0f));
	entityPosition.y = Warp(entityPosition.y, (entityHeight / 2.0f), ((-1.0f * entityHeight) / 2.0f));

	entitySpd = entityVelocity.vLength();

	Entity::Update(deltaTime);
}

void Asteroid::Render(void){

	glLoadIdentity();
	glTranslatef(entityPosition.x, entityPosition.y, 0.0f);
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



