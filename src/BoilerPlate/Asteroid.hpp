#pragma once

#ifndef ASTEROID_H
#define ASTEROID_H

#include "Entity.hpp"

using namespace std;

class Asteroid :public Entity {

private:
	Vector2* asteroidPosition;
	vector <Vector2> asteroidPts;
	enum struct asteroidType {
		SMALL_ASTEROID = 1,
		MEDIUM_ASTEROID = 2,
		BIG_ASTEROID = 3
	};
	int asteroidSize;
	float asteroidMass;
	float asteroidOrientationAngle;
	const float asteroidMovementSpd = 50.0f;
	const float asteroidRotationSpd = 35.0f;


public:
	Asteroid(float entityWidth, float entityHeight);
	Asteroid(asteroidType);

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

