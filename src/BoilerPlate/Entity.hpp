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
	float entityWidth;
	float entityHeight;
	Vector2 entityVelocity;
	float entitySpd;
	bool isEntityMoving;
	vector <Vector2> entityPoints;
	float entityMaxWidth;
	float entityMinWidth;
	float entityMaxHeight;
	float entityMinHeight;

public:
	Entity();
	Entity(float eWidth, float eHeight);
	float GetEntityRadius();
	virtual void Render(void);
	virtual void Update(float);
	virtual void MoveForward(void);
	virtual void SetEntityPoints(void);
	void DrawEntity(void);
	float Warp(float, float, float);

};
#endif // !_ENTITY_H_