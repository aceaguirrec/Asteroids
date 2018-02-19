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
	vector <Vector2> entityPoints;

public:
	Entity();

	virtual void Render(void);
	virtual void Update(void);
	virtual void MoveForward(void);
	virtual void SetEntityPoints(void);
	void DrawEntity(void);
	float Warp(float, float, float);

};
#endif // !_ENTITY_H_