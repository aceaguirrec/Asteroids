#pragma once

#ifndef ASTEROID_H
#define ASTEROID_H

#include "Entity.hpp"

using namespace std;

class Asteroid :public Entity {

private:
	vector <Vector2> asteroidPts;
	enum asteroidSize {SMALL_ASTEROID, MEDIUM_ASTEROID, BIG_ASTEROID};
public:
	Asteroid();

	void Update(void) override;
	void Render(void) override;

	float Warp(float asteroidCoordinate, float borderMinValue, float borderMaxValue);
	void SetAsteroidPoints(void);
	void DrawAsteroid(void);

};
#endif //!_ASTEROID_H

