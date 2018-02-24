#pragma once

#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Vector2.hpp"
#include "MathUtilities.h"
#include <vector>

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

using namespace std;

class Entity {

protected:
	Vector2* entityPosition;
	float entityOrientationAngle;
	float entityMass;
	float entityRadius;
	Vector2* entityVelocity;
	bool isEntityMoving;
	vector <Vector2> entityPoints;
	float entityMaxWidth;
	float entityMinWidth;
	float entityMaxHeight;
	float entityMinHeight;

public:
	Entity(float entityWidth, float entityHeight);
	virtual void Render(void);
	virtual void Update(float);
	virtual void MoveForward(void);
	virtual void SetEntityPoints(void);
	void ScreenCalculations(float entityWidth, float entityHeight);
	void DrawEntity(void);
	float Warp(float, float, float);

};
#endif // !_ENTITY_H_