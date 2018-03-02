#pragma once

#ifndef ASTEROID_H
#define ASTEROID_H

#include "Entity.hpp"

using namespace std;

class Asteroid :public Entity {

private:
	vector <Vector2> asteroidPts;
	int asteroidSize;
	float asteroidMovementSpd;
	bool hasBeenImpacted;


public:
	Asteroid(float entityWidth, float entityHeight, int size);

	void Update(float deltaTime);
	void Render(void) override;



	float Warp(float asteroidCoordinate, float borderMinValue, float borderMaxValue);
	void SetAsteroidPoints(void);
	void DrawAsteroid(void);
	Vector2 GetAsteroidPosition(void);
	int GetAsteroidSize(void);
	void AsteroidImpulse(void);
	void GenerateAsteroidOrientationAngle(void);

};
#endif //!_ASTEROID_H

