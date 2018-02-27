#pragma once

#ifndef ASTEROID_H
#define ASTEROID_H

#include "Entity.hpp"

using namespace std;

class Asteroid :public Entity {

private:
	Vector2* asteroidPosition;
	vector <Vector2> asteroidPts;
	int asteroidSize;
	float asteroidMass;
	float asteroidRadius;
	float asteroidOrientationAngle;
	const float asteroidMovementSpd = 50.0f;
	const float asteroidRotationSpd = 35.0f;
	bool hasBeenImpacted;


public:
	Asteroid(float entityWidth, float entityHeight, int size);

	void Update(float deltaTime);
	void Render(void) override;

	float Warp(float asteroidCoordinate, float borderMinValue, float borderMaxValue);
	void SetAsteroidPoints(void);
	void DrawAsteroid(void);
	int GetAsteroidSize(void);
	void AsteroidImpulse(void);
	void GenerateAsteroidOrientationAngle(void);

};
#endif //!_ASTEROID_H

