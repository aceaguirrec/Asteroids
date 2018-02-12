#pragma once
#include "Vector2.hpp"

/*=================
* Player 
*declaration
=================*/
class Player {
					
private:
	Vector2 position;

public:
	Player();
	void Update();
	void Render();
	float Warp(float shipPosition, int borderMinValue, int borderMaxValue);
	void move(Vector2& newPosition);
	void moveForward(Vector2& newPos);
	void rotateLeft(void);
	void rotateRight(void);
};