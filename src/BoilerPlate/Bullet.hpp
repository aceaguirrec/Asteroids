#pragma once
#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "Vector2.hpp"
#include "Entity.hpp"
#include <SDL2/SDL_opengl.h>

const int maxBulletLifeSpan = 0;

class Bullet : public Entity {
private:
	vector <Vector2> bulletPts;
	int shotAngle;
	int remainingBulletLifeSpan;


public:
	Bullet(float bWidth, float bHeight);
	bool isInFlight(void);
	void SetBulletPoints(void);
	void DrawBullet(void);
	void Update(float deltaTime);
	void Render(void);




}
#endif // BULLET_H_INCLUDED