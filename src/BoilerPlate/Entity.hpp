#pragma once
#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Vector2.hpp"
#include "MathUtilities.h"
#include <cmath>
#include <vector>

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

using namespace std;

class Entity {

protected:
	Vector2 entityPosition;
	float entityOrientationAngle;
	float entityMass;
	float entityRadius;
	float entityWidth;
	float entityHeight;
	Vector2 entityVelocity;
	float entitySpd;
	vector <Vector2> entityPoints;
	bool isColliding;
	bool isDebugging;
	

public:
	Entity();
	Entity(float eWidth, float eHeight);
	Vector2 GetEntityPosition(void);
	float GetEntityRadius(void);
	float GetDistanceBtwn2Entities(Vector2 position);
	virtual void Render(void);
	virtual void Update(float);
	virtual void MoveForward(void);
	virtual void SetEntityPoints(void);
	void DrawEntity(void);
	float Warp(float, float, float);
	void DrawDebuggingCircle(void);
	void SetCollidingStatus(bool collidingStatus);
	void SetDebuggingStatus(bool debuggingStatus);

};
#endif // !_ENTITY_H_