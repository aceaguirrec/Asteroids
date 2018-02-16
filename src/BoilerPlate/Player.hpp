#pragma once
#include "Vector2.hpp"

/*=================
* Player 
*declaration
=================*/
class Player {
					
private:
	Vector2 position;
	float mass;

public:
	Player();
	void Update();
	void Render();
	float Warp(float shipPosition, int borderMinValue, int borderMaxValue);
	void moveForward(Vector2& newPosition);
	void rotateLeft(void);
	void rotateRight(void);
	bool isThrusterActive = false;
};